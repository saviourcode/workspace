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
    2. Data section - global variables
    3. Heap section - memory that is dynamically allocated during program runtime
    4. Stack section - temporary data storage when invoking functions (such as function parameters, return addresses, and local variables)
4. The size of text and data sections are fixed, as their sizes do not change during program runtime. However, the stack and heap sections can shrink and grow dynamically during program execution.
