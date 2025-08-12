A process is created when a program runs. Process acts as a container for resources (memory, files etc..) and helps provide isolation. By itself process doesn't execute any code. Threads are execution units. When a process is created, it starts with one thread but it can make more, as for how refer [Multi-threading](../threads/Multi-threading.md).
The kernel sets up a virtual address space divided into pages of fixed size (ex- 4KB). This space includes code, data stack,and heap regions.[Memory map of processes](Memory%20map%20of%20processes.md)


## pages

- a node can only have access and information about it's child it has no information, whatsoever about its parent
- kernel divides the total available memory and gives the process this memory in form of pages (4kb usually). 
- Though the program believes that it is addressing the entire addressable memory, it is just an abstraction created by the kernel for the process 
### size of a page
Pagesize of 4KB is still used by default. The reason is, that it simply saves a lot of memory and because of TLB (translation lookaside buffer) it doesn't impact performance too much either.

`grep -ir pagesize /proc/self/smaps`  
will show you the KernelPageSize and MMUPagesize

> Page size is enforced at a hardware level so you can only support what hardware supports. For example, Linux uses 8KiB page size on SPARC chips because that's what that chip uses. On Intel, it is 4KiB and, on more recent Intel chips, it also supports 2MiB and, most recently, 1GiB. Linux can also use 2MiB via the hugepages feature, but it's not default because you waste half a page, on average, per process and that can add up. ARM64, as used for Apple Silicon, apparently can support 4KiB, 16KiB, and 64KiB. There are some reports of Linux kernels using the 16KiB mode, same as macOS, but it sounds like it's still experimental in nature at this point.


### segmentation of page
The segmentation of process's memory is handled by kernel and the compiler, based on the executable's structure and the runtime environment. 

|Segment|Allocation Trigger|Growth Direction|Managed By|
|---|---|---|---|
|**Code**|Program load (OS)|Fixed|OS|
|**Data**|Program load (OS)|Fixed|OS|
|**Heap**|First `malloc`/`new` (OS/libc)|Upward|Memory allocator (e.g., `glibc`)|
|**Stack**|Thread creation (OS)|Downward|Compiler/OS (via ISA)|

### Starting of a process and memory allocation 
a process doesn't start with a single page. It begins with a structured virtual address space which has already been segmented into multiple regions. The segmentation  is orchestrated by the OS's kernel using MMU's support. 

## Process Control Block(PCB)
this is a data-structure created by the OS for each process during initialization (via fork() or execute()). It is exclusive controlled and managed by the kernel. 
- It is stored in a protected kernel memory
- only kernel can access or modify the the PCB
- user processes cannot directly access this memory they can only access things like PID using system calls.
### Data Management in the PCB

- **Data Segment/BSS Addresses**: The PCB stores pointers to the process's memory segments, including:
    
    - Base addresses and limits for the **data segment** (initialized variables) and **BSS** (uninitialized data)[1](https://www.perplexity.ai/search/how-does-the-page-get-segmente-z4TyU7dhRX6tYdhdNeDgog#user-content-fn-memory%5E).
        
    - Heap and stack pointers for dynamic memory management[1](https://www.perplexity.ai/search/how-does-the-page-get-segmente-z4TyU7dhRX6tYdhdNeDgog#user-content-fn-memory%5E).
        
- **PID Storage**: The Process ID (PID) is stored directly in the PCB and used by the kernel for process identification[1](https://www.perplexity.ai/search/how-does-the-page-get-segmente-z4TyU7dhRX6tYdhdNeDgog#user-content-fn-memory%5E).

 - **Key Fields**:

	| Field             | Description                                 |
	| ----------------- | ------------------------------------------- |
	| `pid`             | Process ID                                  |
	| `state`           | Process state (running, blocked, etc.)      |
	| `thread_list`     | Pointers to TCBs of threads                 |
	| `memory_maps`     | Segment addresses (code, data, heap, stack) |
	| `scheduling_info` | Priority, CPU time, etc.                    |


	the TCB to threads is stored as a linked list in the PCB, 