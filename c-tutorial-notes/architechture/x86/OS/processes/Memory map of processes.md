![](attachments/Pasted%20image%2020250615100026.png)

The memory is logically divided as follows:

- The stack contains local and temporary variables as well as return addresses.
- The heap contains dynamically allocated variables.
- Text (Code) – these are the instructions to execute.
- Initialized data – contains initialized variables.
- Uninitialized data – the block starting symbol (BSS) contains declared but uninitialized static variables.
anything within BSS is initialized to 0
In stack theres is no initialization, that is why we can see garbage values.

### how the split occurs
|Segment|Allocation Trigger|Growth Direction|Managed By|
|---|---|---|---|
|**Code**|Program load (OS)|Fixed|OS|
|**Data**|Program load (OS)|Fixed|OS|
|**Heap**|First `malloc`/`new` (OS/libc)|Upward|Memory allocator (e.g., `glibc`)|
|**Stack**|Thread creation (OS)|Downward|Compiler/OS (via ISA)|

