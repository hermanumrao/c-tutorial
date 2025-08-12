### Calloc fn:
The calloc() function stands for Contiguous Allocation. It is used to allocate memory for multiple elements and also initializes all of them to zero.


### Differeance

| Feature        | malloc()                         | calloc()                                 |
| -------------- | -------------------------------- | ---------------------------------------- |
| Initialization | Does not initialize memory       | Initializes memory to zero               |
| Arguments      | Takes total size in bytes        | Takes number of elements and size        |
| Use Case       | When no initialization is needed | When zero-initialized memory is required |


### When to Prefer calloc() Over malloc()

- When you need all allocated values to be initialized to zero by default.
    
- For programs involving structures or arrays where zero values avoid undefined behavior.
    
- When working with bitmaps, flags, or memory buffers that should start clean.