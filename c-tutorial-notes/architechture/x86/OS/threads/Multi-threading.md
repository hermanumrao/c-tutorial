In C language, **[POSIX](../POSIX.md)<pthread.h>** standard API (Application program Interface) for all thread related functions. It allows us to create multiple threads for concurrent process flows. 


- In an operating system that supports multi-threading, the process can consist of many threads. But threads can be effective only if the CPU is more than 1 otherwise two threads have to context switch for that single CPU.

- All threads belonging to the same process ==share - code section, data section, and OS resources== (e.g. open files and signals)

- But ==each thread has its own TCB== (thread control block) - thread ID, program counter, register set, and a stack

- Any operating system process can execute a thread. we can say that single process can have multiple threads.

- ==Priority can be assigned== to the threads just like the process, and the highest priority thread is scheduled first.

- Each thread has its own [Thread Control Block (TCB)](https://www.geeksforgeeks.org/thread-control-block-in-operating-system). Like the process, a context switch occurs for the thread, and register contents are saved in (TCB). As threads share the same address space and resources, synchronization is also required for the various activities of the thread.

## How Do Threads Share Resources

Threads are usually described as lightweight processes. They run specific tasks within a process. Each thread has its id, a set of registers, the stack pointer, the program counter, and the stack.

![](attachments/Pasted%20image%2020250615095336.png)

**The process divides the stack area and gives each thread a portion of it.**

As shown in the figure below, the allocated stack area for a thread contains at least the following:

- the called function’s arguments
- local variables
- a return memory address that points where to return the function’s output

In addition, when a thread completes its task, the stack area of the corresponding thread gets reclaimed by the process. So, although each thread has its own stack, thread-specific stacks are parts of the same stack area the process owns.

![](attachments/Pasted%20image%2020250615095840.png)

