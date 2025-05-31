#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CACHE_LENGTH 3

struct List {
  int data;
  struct List *next;
};

struct Cache {
  struct List *head;
  int hash[CACHE_LENGTH][CACHE_LENGTH];
};

void init_cache(struct Cache *cache) {
  cache->head = NULL;
  for (int i = 0; i < CACHE_LENGTH; i++) {
    for (int j = 0; j < CACHE_LENGTH; j++) {
      cache->hash[i][j] = -1;
    }
  }
}

struct List *create_node(int data, struct List *next) {
  struct List *node = (struct List *)malloc(sizeof(struct List));
  node->data = data;
  node->next = next;
  return node;
}

void displayList(struct List *strt) {
  struct List *tmp = strt;
  while (tmp != NULL) {
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

bool is_in_hash(struct Cache *cache, int data) {
  int row = data % CACHE_LENGTH;
  for (int i = 0; i < CACHE_LENGTH; i++) {
    if (cache->hash[row][i] == data)
      return true;
  }
  return false;
}

void insert_in_hash(struct Cache *cache, int data) {
  int row = data % CACHE_LENGTH;
  for (int i = 0; i < CACHE_LENGTH; i++) {
    if (cache->hash[row][i] == -1 || cache->hash[row][i] == data) {
      cache->hash[row][i] = data;
      return;
    }
  }
}

void remove_from_hash(struct Cache *cache, int data) {
  int row = data % CACHE_LENGTH;
  for (int i = 0; i < CACHE_LENGTH; i++) {
    if (cache->hash[row][i] == data)
      cache->hash[row][i] = -1;
    return;
  }
}

void freeList(struct List *head) {
  struct List *current = head;
  struct List *next;

  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  printf("list has been freed\n");
}
void add_data(struct Cache *cache, int data) {
  struct List *node = create_node(data, cache->head);
  cache->head = node;
  insert_in_hash(cache, data);

  struct List *tmp = cache->head;
  for (int i = 1; i < CACHE_LENGTH && tmp->next; i++) {
    tmp = tmp->next;
  }

  if (tmp && tmp->next) {
    remove_from_hash(cache, tmp->next->data);
    freeList(tmp->next);
    tmp->next = NULL;
  }
}

void get_data(struct Cache *cache, int data) {
  struct List *prev = NULL;
  struct List *curr = cache->head;

  while (curr != NULL) {
    if (curr->data == data) {
      if (prev != NULL) {
        prev->next = curr->next;
        curr->next = cache->head;
        cache->head = curr;
      }
      return;
    }
    prev = curr;
    curr = curr->next;
  }
  add_data(cache, data);
}

/* void get_data(int data, struct Cache *cache) { */
/*   struct List *prev = NULL; */
/*   struct List *tmp = cache->head; */
/*   struct List *next = NULL; */
/*   int cnt = 0; */
/*   while (tmp != NULL && cnt < CACHE_LENGTH) { */
/*     next = tmp->next; */
/*     if (tmp->data == data) { */
/*       if (prev != NULL) */
/*         prev->next = next; */
/*       if (tmp != cache->head) { */
/*         tmp->next = cache->head; */
/*         cache->head = tmp; */
/*       } */
/*       return; */
/*     } */
/*     prev = tmp; */
/*     tmp = tmp->next; */
/*   } */
/*   cache->head = create_node(data, cache->head); */
/*   insert_in_hash(cache, data); */
/*   tmp = cache->head; */
/*   for (int i = 1; i < CACHE_LENGTH && tmp->next; i++) */
/*     tmp = tmp->next; */
/**/
/*   if (tmp && tmp->next) { */
/*     remove_from_hash(cache, tmp->next->data); */
/*     freeList(tmp->next); */
/*     tmp->next = NULL; */
/*   } */
/* } */

int main(int argc, char *argv[]) {
  struct Cache cache;
  init_cache(&cache);
  int access_queue[] = {1, 2, 3, 2, 4, 5, 6};
  int n = sizeof(access_queue) / sizeof(access_queue[0]);
  for (int i = 0; i < n; i++) {
    /* add_element(&cache, access_queue[i]); */
    if (is_in_hash(&cache, access_queue[i]))
      get_data(&cache, access_queue[i]);
    else
      add_data(&cache, access_queue[i]);
    displayList(cache.head);
  }

  return EXIT_SUCCESS;
}
