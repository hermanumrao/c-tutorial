## Least Recently used cache
Basically the data which was used most recently is retained and the data which wasn't used recently and is above our cache size is deleted.
Entire stuff works on  basic linked-list structure[[Basic struct of linked-lists in C]].
![[Pasted image 20250601100028.png]]
the 1st node is the most recently used one.

### basic impl.
```c
void get_data(int data, struct List **cache) {
  struct List *prev = NULL;
  struct List *tmp = *cache;
  struct List *next = NULL;
  int cnt = 0;
  while (tmp != NULL && cnt < CACHE_LENGTH) {
    next = tmp->next;
    if (tmp->data == data) {
      if (prev != NULL)
        prev->next = next;
      if (tmp != *cache) {
        tmp->next = *cache;
        *cache = tmp;
      }
      return;
    }
    prev = tmp;
    tmp = tmp->next;
  }
  *cache = create_node(data, *cache);
  tmp = *cache;
  for (int i = 1; i < CACHE_LENGTH && tmp->next; i++)
    tmp = tmp->next;

  if (tmp && tmp->next) {
    freeList(tmp->next);
    tmp->next = NULL;
  }
}

```

#### test cases:
1. ##### empty list
	easiest, just create a new node with data and return it
2. ##### partially filled data miss
   again just create a new node and add it at the front.
3. ##### data already exists
   find the location of the data and then move the node with the required data to front.
4. ##### fully filled, data miss
   first add node to the front and then delete the excess nodes at the front.


### a lil. better
Well till now we only used a linked list to check recency of the data but then this isn't enough. Linked lists have a time complexity of O(n). imagine traversing the entire length of list to check existence of the data.
This is where hash-tables and hash-maps help.
**here we will be implementing hash tables **...

So first we have our initial linked list structure and then we have our hash table with pointers to the original linked list...

```c
struct List {
  int data;
  struct List *next;
};

struct Cache {
  struct List *head;
  struct List *hash[CACHE_LENGTH][CACHE_LENGTH];
};

```

All though this introduces new challenges but then it makes the lookup time complexity O(1).
find the whole code at @ [https://github.com/hermanumrao/c-tutorial/blob/main/data_struct/linked_lists/complex_lru_cache.c](https://github.com/hermanumrao/c-tutorial/blob/main/data_struct/linked_lists/complex_lru_cache.c)

### arguably good
well now, there a better thing, we call hash map. This has a time complexity of O(log(n). But then this helps in parallel lookup. Well that is a good thing, but then there also also issues like, how can the logic of this be hard-wired into the cache for better lookup's, hence i don't see this being used...
find more @ [[hash-map vs hash-table]]
 - important feature that hash-map gives parallel search but then this is rarely required. so we obviously prefer using hash-tables.