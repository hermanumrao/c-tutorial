Threads in C are typically created using the POSIX threads (pthreads) library. 

- Use `pthread_create()` to spawn a new thread, specifying:
    - A `pthread_t` handle to identify the thread.
    - Thread attributes (e.g., stack size, scheduling policy).
    - The function the thread will execute.
    - Arguments to pass to that function.

Example:
```c
pthread_t thread_id;   pthread_create(&thread_id, NULL, thread_function, NULL);

```


## Thread Control Blocks (TCBs)
-  Each thread has its own **Thread Control Block (TCB)**, not stored directly in the Process Control Block (PCB).
- The PCB maintains a **linked list of TCB pointers** for threads within the process

- Each TCB contains thread-specific metadata:
    
    - Thread ID (TID)
    - Stack pointer
    - Register states
    - Scheduling priority
    - Pointer to the parent Process Control Block (PCB)

### why linked list
well it could have been a tree structure, but then there is a reason for list structure.
Even-though tree structure is used in places where we have thousands of threads. But then for normal systems is is a linked list by default.
the main reason for this is that insertion in a linked-list is an O(1) operation.
normally it is very rear that we access threads by their TID's so the linked list is a better approach.


**TCB is again stored in the kernel space** to keep-it safe. Kernel is what creates and manages threads. user programs can only access it using system calls.