## std::vector

Except for the [`std::vector<bool>`](https://en.cppreference.com/w/cpp/container/vector_bool.html "cpp/container/vector bool") partial specialization, the elements are stored contiguously, which means that elements can be accessed not only through iterators, but also using offsets to regular pointers to elements. This means that a pointer to an element of a vector may be passed to any function that expects a pointer to an element of an array.

The storage of the vector is handled automatically, being expanded as needed. Vectors usually occupy more space than static arrays, because more memory is allocated to handle future growth. This way a vector does not need to reallocate each time an element is inserted, but only when the additional memory is exhausted. The total amount of allocated memory can be queried using [capacity()](https://en.cppreference.com/w/cpp/container/vector/capacity.html "cpp/container/vector/capacity") function. Extra memory can be returned to the system via a call to [shrink_to_fit()](https://en.cppreference.com/w/cpp/container/vector/shrink_to_fit.html "cpp/container/vector/shrink to fit")[[1]](https://en.cppreference.com/w/cpp/container/vector.html#cite_note-1).

Reallocations are usually costly operations in terms of performance. The [reserve()](https://en.cppreference.com/w/cpp/container/vector/reserve.html "cpp/container/vector/reserve") function can be used to eliminate reallocations if the number of elements is known beforehand.

The complexity (efficiency) of common operations on vectors is as follows:

- Random access - constant 𝓞(1).
- Insertion or removal of elements at the end - amortized constant 𝓞(1).
- Insertion or removal of elements - linear in the distance to the end of the vector 𝓞(n).
## vector vs array vs malloc

|**Feature**|**Array**|**malloc**|**vector** (C++ STL)|
|---|---|---|---|
|**Allocation**|Compile-time (static) or runtime (VLA in C99, stack)|Runtime (heap)|Runtime (heap)|
|**Size**| **Fixed at compile time** (for static arrays)| **Variable at runtime**| **Dynamic**, can grow/shrink as needed|
|**Location**| **Stack / Data segment / BSS**| **Heap**| **Heap** (even though object may live on stack)|
|**Management**|Automatic (freed when out of scope)|Manual (`free` required)|Automatic (RAII; destructors handle cleanup)|
|**Resizing**| Not possible| Possible with `realloc`| Possible using `push_back`, `resize`, etc.|
|**Speed**| Fastest access (no indirection)|Slightly slower (heap allocation)|Slightly slower (due to bounds checking and allocation overhead)|
|**Error Handling**|Limited| Returns `NULL` on failure| Throws exception (`std::bad_alloc`) on failure|
|**Continuity**| **Continuous block of memory**| Not guaranteed (especially after `realloc`)| **Continuous block of memory**|
|**Creation**|Must specify size and type at declaration|Requires total size in bytes, not type-safe|Type-safe, no need to specify size up front|
|**Methods**| Not many methods built-in (manual handling)| Not many methods built-in (only allocate memory)| Rich set of built-in methods (`push_back`, `insert`, `erase`, etc.)|
|**Access**| **Indexed**, or pointer arithmetic from first element| Indexed (via pointer), but manual| **Indexed + iterator-based** access|
|**Pointer Decay**| Pointer to array decays to pointer to first element|Might change during `realloc`, invalidating previous pointer| Iterator and pointer invalidation on reallocation|
|**Copying**| No direct copying method (requires loops or `memcpy`)| No direct copying (manual or `memcpy`)| Directly copyable via copy constructor or assignment|
|**Type Safety**| Type-safe| Not type-safe| Fully type-safe|
|**Use in Classes**|Not easily used (needs special care)|Not recommended directly (raw pointers discouraged)| Designed for class usage|
|**Initialization**|Easy with initializer list (`int arr[] = {1, 2, 3};`)|Manual initialization (`memset`, loops)| Constructor-based or initializer list|
|**Flexibility**|Low|Moderate (with manual control)| High (abstracts most details)|


## use of iterators for vectors

Normally with arrays, we only need a pointer to the first element to traverse the entire array. However, vectors don't have a fixed size. As we keep pushing new items, the capacity needs to increase. At some point, if it's no longer possible to maintain contiguous memory because the current memory chunk is full, we need to find another free chunk of contiguous memory and relocate all the data to that location.

so 