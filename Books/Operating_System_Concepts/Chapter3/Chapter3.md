# Motivation
1. A process is the unit of work in most systems.
2. Operating-system processes execute system code, and user processes execute user code. All these processes may execute concurrently.
3. Modern OS supoort processes having mulitple threads of control. On systems with multiple hardware processing cores these threads can run in parallel.
4. One of the most important aspects of an OS is how it schedules threads onto available processing cores. There are several choices available to programmers.
5. Early computers allowed only one process to run at any given time. But the contemporary computer systems allow mulitple programs to be loaded into memory and executed concurrently.
6. And this resulted in the notion of what we call as `process`.
7. So, a system in essence consists of a collection of processes, some executing user code, others executing operating system code.
# Process Concept
1. In time-shared systems with multi user, there are can many processes. And even in a single-user time, a user can execute various applications all at once.
2. The term job has historical significance due to the fact that OS theory and terminology was developed during a time when the major activity of operating systems was job processing.
## The Process
1. A Process is a program in execution.
2. The status of the current activity of a process is represented by the value of the `program counter` and the contents of the processor's registers.
3. The memory layout of a process generally involves the following structure:
    1. Text section - the executable code
    2. Data section - global variables, initialized (BSS, block started by symbol) and uninitialized data
    3. Heap section - memory that is dynamically allocated during program runtime
    4. Stack section - temporary data storage when invoking functions (such as function parameters, return addresses, and local variables)

![Memory Layout of C Program](./Memory_Layout.PNG)

4. The size of text and data sections are fixed, as their sizes do not change during program runtime. However, the stack and heap sections can shrink and grow dynamically during program execution.
5. Each time a function is called, an activation record containing function parameters, local variables, and the return address is pushed onto the stack; when control is returned from the function, the activation record is popped from the stack.
6. The OS ensures that heap and stack don't overlap each other.
7. A Program is a passive entity which is just sitting on the disk. Whereas, a process is a active entity which is currently in execution.
8. A program becomes a process when an executable file is loaded into memory.
9. A Process may call another process to execute. For example, in Java, the JVM is a process that actually intreprets the Java Program.
## Process State
1. As a process executed, it changes state.
2. A process may be in one of the following states:
    1. New - The process is being created
    2. Running - Instructions are being executed
    3. Waiting - The process is waiting for some event ot occur (such as an I/O completion or reception of a signal).
    4. Ready - The process is waiting to be assigned to a processor.
    5. Terminated - The Process has finished execution

![Diagram of Process State](./Diagram_Of_Process_State.PNG)

3. Only one process may be in running state inside the processor. But many processes can be ready or waiting state.

## Process Control Block
1. Each process is represented in the operating system by a `process control block (PCB)` - also called a `task control block (TCB)`
2. It contains various information about the process such as:
    1. Process state - The state may be new, ready, running, waiting, halted and so on.
    2. Program Counter - The counter indicates the address of the next instruction to be executed for this process.
    3. CPU registers - The registers vary in number and type, depending on the computer architecture (like x86, AMD etc). They include accumulators, index registers, stack pointers and general-purpose registers, plus any condition-code information. This information is important to allow the process to be continued correctly afterwards when it is rescheduled to run.
    4. CPU-scheduling information - This information includes a process priority, pointers to scheduling queues, and any other scheduling parameters.
    5. Memory-management information - This information may include such items as the value of the base and limit registers and the page tables, or the segment tables, depending on the memory system used by the operating system.
    6. Accounting information - It includes the amount of CPU and real time used, time limits, accound numbers, job or process numbers and so on.
    7. I/O status information - It includes the list of I/O devices allocated to the process, a list of open files and so on.

![Process Control Block](./PCB.PNG)

In brief, the PCB simply serves as the repository for all the data needed to start, or restart, a process, along with some accounting data.

> More information: The process contol block in the Linux operating system is represented by the C structure `task_struct`, which is found  in the `<include/linux/sched.h>` include file in the kernel source-code directory. For the fields of this struct are given below:
```c
long state; // state of the process
struct sched_entity se; // scheduling information
struct task_struct *parent // this process's parent
struct list_head children; // this process's children
struct files_struct *files; // list of open files
struct mm_struct *mm; // address space
```
> As we can see, it contains important information like state of the process, scheduling and memory-management information, list of open files and pointers to the process's parent and a list of its children and siblings.

> Within the Linux Kernel, all active processes are represented using doubly linked list of `task_struct`. The kernel maintains a pointer-`current`-to the process currently executing on the system, as shown below:
![Doubly Linked List](./DoublyLL.PNG)

## Threads
1. A process is a program that performs a single thread of execution. For example, when a process is running a word-processor program, a single thread of instructions is being executed.
2. This single thread of control allows the process to perform only one task at a time.
3. However, most modern operating systems have extended the process concept to allow a process to have multiple threads of execution and thus to perform more than one task at a time.
4. This feature is especially benefical on multicore systems, where multiple threads can run in parallel. Like for example, a multithreaded word processor could, assign one thread to manage user input while another thread runs the spell checker.
5. On systems that support threads, the PCB is expanded to include information for each thread
# Process Scheduling
1. We must always have maximum CPU utilization.
2. The objective of time sharing is to switch a CPU core among processes so frequently that users can interact with each program while it is running.
3. For that, the process scheduler selects an available process (possibly from a set of several available processes) for program execution on a core. Because each CPU core can run one process at a time.
4. For a system with a single CPU core, there will never be more than one process running at a time, whereas a multicore system can run multiple processes at one time.
5. If there are more processes than cores, excess processes will have to wait until a core is free and can be rescheduled. The number of processes currently in memory is known as the `degree of multiprogramming`
6. For our objective of multiprogramming and time-sharing, the process can be generalized into I/O bound or CPU-bound. I/O bound processes makes frequent I/O requests and less CPU time whereas CPU bound processes make less I/O requests and takes more CPU time.
## Scheduling Queues
1. As processes enter the system, they are put into a `ready queue`, where they are ready and waiting to execute on a CPU's core.
2. The queue is generally stored as a linked-list, a ready-queue header contains pointers to the first PCB in the list, and each PCB includes a pointer field that points to the next PCB in the ready queue.
3. There are other queues as well, such as for processes that are waiting for the I/O devices are placed in a `wait queue`.

![Queues](./Queue.PNG)

The common way to understand process scheduling is via the `queueing diagram` such as that in the below figure:

![Queueing Diagram](./Queueing_Diagram.PNG)

A new process is initially put in the ready queue. It waits there until it is selected for execution, or dispatched. Once the process is allocated a CPU core and is executing, one of several events could occur:

    1. The process could issue an I/O request and then be placed in an I/O wait queue.
    2. The process could create a new child process and then be placed in a wait queue while it awaits the child's termination.
    3. The process could be removed forcibly from the core, as a result of an interrupt or having its time slice expire, and be put back in the ready queue.

In the first two cases, the process will be placed in the ready state queue once the wait is done. In the third case, the process is directly put in the ready state. A process continues this cycle until it terminates, at which time it is removed from all queues and has its PCB and resources deallocated.

## CPU Scheduling
1. The role of the `CPU scheduler` is to select from among the processes that are in the ready queue and allocate a CPU core to one of them.
2. The CPU scheudluer must select a new process for the CPU frequently and must not keep the CPU idle.
3. When the main memory is overcommitted with the processes, the scheduler might swap out some processes to disk, where it's data is stored and when it's free again it will bring the process back by swapping in. This process is known as `swapping`
## Context Switch
1. Switching the CPU core to another process requires performing a state save of the current process and a state restore of a different process. This task is known as a `context switch`.
2. As we saw earlier, the `context` of a process is saved on the PCB. It includes the value of the CPU registers, the process state and memory-management information.
3. There is always a overhead in `context switching` and the switching speed varies from machine to machine, depending upon memory speed, the number of registers that must be copied, and the existence of special instrutions (such as a single instruction to load or store all registers).

![Context Switch](./Context_switch.PNG)

# Operations on Processes
The processes in most systems can execute concurrently, and they may be created or deleted dynamically. Thus, these systems must provide a mechanism for process creation and termination.

## Process Creation
1. A process that creates more processes of it's own becomes the parent process and the process it created becomes child processes. Also, each of these child processes may in turn create other processes, forming a `tree` of processes.
2. Most OS assign a `Process Identifier` or (PID) to each process.
3. 