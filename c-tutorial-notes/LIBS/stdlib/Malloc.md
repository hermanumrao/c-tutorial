The malloc() function stands for __Memory Allocation__ . It is used to dynamically allocate a single block of memory of the specified size during the execution of the program.


## working
Now malloc is a part of the [stdlib_h](stdlib_h.md) library,
This  means it ==runs only in the user space.== It has nothing to do with what is happening in the kernel space. But then how does it allocate memory?

### memory allocation
Well the memory allocation using malloc is surprisingly simple. When a program is run, a process is created, a page is created for this process. The page 