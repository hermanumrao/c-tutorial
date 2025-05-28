#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct List {
  int a;
  struct List *next;
};

struct List *createNode(int val, struct List *next) {
  struct List *node = (struct List *)malloc(sizeof(struct List));
  node->a = val;
  node->next = next;
  return node;
}

void displayList(struct List *strt) {
  struct List *tmp = strt;
  while (tmp != NULL) {
    printf("%d ", tmp->a);
    tmp = tmp->next;
  }
  printf("\n");
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

int insertBegining(int val, struct List **head) {
  *head = createNode(val, *head);
  return EXIT_SUCCESS;
}

int insertEnd(int val, struct List **head) {
  struct List *node = createNode(val, *head);
  if (*head == NULL) {
    *head = node;
    return EXIT_SUCCESS;
  }
  struct List *tmp = *head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = createNode(val, tmp->next);
  return EXIT_SUCCESS;
}

struct List *reverseList(struct List *head) {
  struct List *prev = NULL;
  struct List *tmp = head;
  struct List *next = NULL;

  while (tmp != NULL) {
    next = tmp->next;
    tmp->next = prev;
    prev = tmp;
    tmp = next;
  }
  return prev;
}

/* int insert(int val, int pose, struct List **head) { */
/*   if (pose < 0 || *head == NULL) { */
/*     insertBegining(val, head); */
/*     return EXIT_SUCCESS; */
/*   } */
/*   struct List *tmp = *head; */
/*   for (int i = 0; i < pose - 1; i++) { */
/*     if (tmp->next == NULL) { */
/*       fprintf(stderr, "insert to list at wrong location.\n"); */
/*       return EXIT_FAILURE; */
/*     } */
/*     tmp = tmp->next; */
/*   } */
/*   tmp->next = createNode(val, tmp->next); */
/*   return EXIT_SUCCESS; */
/* } */

int main(int argc, char *argv[]) {
  int a[] = {1, 2, 3};
  int n = sizeof(a) / sizeof(a[0]);
  struct List *head = NULL;
  for (int i = 0; i < n; i++) {
    /* head = createNode(a[i], head); */
    insertBegining(a[i], &head);
  }
  insertEnd(0, &head);
  /* insert(0, 2, &head); */
  /* insert(0, 4, &head); */
  /* insert(0, 3, &head); */

  displayList(head);
  head = reverseList(head);
  displayList(head);
  freeList(head);

  return EXIT_SUCCESS;
}
