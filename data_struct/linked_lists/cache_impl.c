#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CACHE_LENGTH = 3;

struct List {
  int data;
  struct List *next;
};

struct List *create_node(int data, struct List *next) {
  struct List *node = (struct List *)malloc(sizeof(struct List));
  node->data = data;
  node->next = next;
  return node;
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

void delDUP(int data, struct List **head) {
  struct List *prev = NULL;
  struct List *tmp = *head;

  while (tmp != NULL) {
    if (tmp->data == data) {
      if (prev == NULL) {
        *head = tmp->next;
        free(tmp);
        tmp = *head;
      } else {
        prev->next = tmp->next;
        free(tmp);
        tmp = prev->next;
      }
    } else {
      prev = tmp;
      tmp = tmp->next;
    }
  }
}

void add_element(struct List **cache, int data) {
  delDUP(data, cache);
  struct List *node = create_node(data, NULL);
  node->next = *cache;
  *cache = node;
  for (int i = 0; i < CACHE_LENGTH - 1 && node->next != NULL; i++)
    node = node->next;
  struct List *tmp = node->next;
  node->next = NULL;
  freeList(tmp);
}

void displayList(struct List *strt) {
  struct List *tmp = strt;
  while (tmp != NULL) {
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  struct List *cache = NULL;
  int access_queue[] = {1, 2, 3, 2, 4};
  int n = sizeof(access_queue) / sizeof(access_queue[0]);
  for (int i = 0; i < n; i++) {
    add_element(&cache, access_queue[i]);
    displayList(cache);
  }

  return EXIT_SUCCESS;
}
