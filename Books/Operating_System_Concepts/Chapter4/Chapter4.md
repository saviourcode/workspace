# Motivation
1. A thread is a basic unit of CPU utilitization; it comprises a thread ID, a program counter (PC), a register set, and a stack.
2. It shares with other threads belonging to the same process its code section, data section, and other operating-system resources, such as open files and signals.
3. If a process has single thread of control then it can only perform a single task at a time, but if a process has multiple thread of control then it can perform multiple task at a time.

![Thread](./thread.PNG)

4. The application of threads can be seen in the case of Web-Server. Early web-servers used to run a single threaded process. It was all good and fun for a single client. But if more than one client wanted to connect then the other clients had to wait for a all time before their turn came. The other solution was to run a dedicated single threaded process for each client on the server. But since we know from the process creation takes alot of overhead and time and resources so, it is still not an effective solution for large amount of client. And besides since the process is going to perform the same task so no point of spawning new processes each time a client wants to connect.    
A different strategy for such type of problem could be create a multithreaded process. When a request is made, rather than creating another process, the server creates a new thread to service the request and resumes listening for additional requests.

![Web Server](./webserver.PNG)

5. Most OS kernels are alos typically multithreaded. During system boot time on Linux systems, several kernel threads are created. Each thread performs a specific task, such as managing devices, memory management, or interrupt handling. `kthreadd` with PID = 2 serves as the parent of all other kernel threads.
6. Programmers who must solve contemporary CPU-intensive problems in data mining, graphics, and artifical intelligence can leverage the power of modern multicore systems by designing solution that run in parallel.
## Benefits
The benefits of multithreaded programming can be borken down into four major categories:
1. Responsiveness: If the time-consuming operation is performed in a seperate, asynchronous thread and some other thread which is active and interacting with the user, the application as a whole remains responsive.
2. Resource sharing: Processes can share resources only via shared memory or message passing techniques. These things needs to be explicitly arranged by the programmer. However, threads share the memory and the resources of the process to which they belong by default. All the threads of the process runs within the same address space.
3. Economy: Allocating memory and resources for process creation is costly. Since, threads share the resources of the process to which they belong, it is more economical to create and context-switch threads. Context-switching in threads is typically faster than between processes.
4. Scalability: The prime benefit of a multithreaded process comes into account when we have multicore system. Because in a multicore system, threads may be running in parallel on different processing cores. A single-threaded process can run on only one processor, regardless how many are available.
# Multicore Programming
1. Consider an application with four threads. On a system with a single computing core, concurrency merely means that execution of the threads will be interleaved over time, because the processing core is capable of executing only one thread at a time.

![Concurrent Task](./concurrent.PNG)

On a system with multiple cores, however, concurrency means that some threads can run in parallel, because the system can assign a separate thread to each core

![Parallel Task](./parallel.PNG)

2. Notice the distinction between concurrency and parallelism. A concurrent system supports more than one task by allowing all the tasks to make progress. In contrast, a parallel system can perform more than one task simultaneously. Thus, it is possible to have concurrency without parallelism. And which is what exactly used to happen with the earlier systems with single CPU, because the CPU scheduler were designed to provide the illusion of parallelism by rapidly switching between processes, thereby allowing each process to make progress. Such processes were running concurrently, and not in parallel.
## Programming Challenges
To make applications fully utilize the benefits of a multicore system by multithreading the process, we need to focus on the below five areas of challenges in programming for multicore systems:
1. Identifying task: This involves determing the areas that can be divided into separate concurrent tasks. Ideally, tasks are independent of one another and thus can run in parallel on individual cores.
2. Balance: The task must perform equal work of equal value. In some instances, a certain task may not contirbute as much value to the overall process as other tasks. Some using a whole complete core for it may not be worth the cost.
3. Data Splitting: Just as applications are divided into separate tasks, the data accessed and manipulated by the tasks must be divided to run on separate cores.
4. Data Dependency: The data accessed by the tasks must be examined for dependencies between two or more tasks. When one task depends on data from another, programmers must ensure that the execution of the tasks is synchronized to accommodate the data dependency.
5. Testing and debugging: When a program is running in parallel on multiple cores, many different execution paths are possible. Testing and debugging such concurrent programs is inherently more difficult.
## Types of Parallelism
1. There are two types of parallelism: data and task.
2. Data Parallelism:  It focuses on distributing substes of the same data across multiple computing cores and performing the same operation on each core.
Eg. Summing the contents of an array of size N. It can be divided into multiple thread like on Dual-Core system, thread A on core 0, could sum the elements [0] to [N/2-1] while thread B on core 1, could sum the elements [N/2] to [N-1].
3. Task Parallelism: It involves distributing not data but tasks (threads) across multiple computing cores. Each thread is performing a unique operation. Different threads may be operating on the same data, or they may be operating on different data.
Eg. Two threads might perfrome a unique statistical operation on the array of elements [0] to [N-1].
4. However, data and task parallelism are not mutually exclusive, and application may use hybrid of these two strategies.
