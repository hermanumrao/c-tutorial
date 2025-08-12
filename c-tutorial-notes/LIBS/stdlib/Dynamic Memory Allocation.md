C provides a feature called Dynamic Memory Allocation. It allows you to allocate memory at runtime, giving your program the ability to handle data of varying sizes. Dynamic resources are stored in the heap memory instead of the stack.

- It is dynamic because it internally uses a double linked list to store it's data.
- all of this happens within the heap no matter where the malloc is called.
- All malloc does is allocate space of the requested size and return its pointer.

## Array vs malloc

| Feature        | Array                                       | `malloc`                                                                 |
| -------------- | ------------------------------------------- | ------------------------------------------------------------------------ |
| Allocation     | Compile-time                                | Runtime                                                                  |
| Size           | ==Fixed at compile time==                   | ==Variable at runtime==                                                  |
| Location       | ==Stack / Data segment / BSS==              | ==Heap==                                                                 |
| Management     | Automatic                                   | Manual (`free` required)                                                 |
| Resizing       | Not possible                                | Possible with `realloc`                                                  |
| Speed          | Faster access                               | Slightly slower access                                                   |
| Error Handling | Limited                                     | Can return `NULL` on allocation failure                                  |
| continuty      | ==continuous block of memmory==             | ==not continuous, uses multiple blocks in form of a doubly linked-list== |
| creation       | specific about size and type of data in it. | it only needs to know the total size nothing else                        |
