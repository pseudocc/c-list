#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list_s list_t;

struct list_s {
  int data;
  struct list_s* next;
};

/**
 * basic operations
 **/
void list_push(list_t** ihead, int data);
int list_pop(list_t** ihead);
void list_free(list_t** ihead);
void list_print(list_t* head, list_t* end);

/**
 * extended operations
 **/
void list_qsort(list_t** ihead);

void list_invert(list_t** ihead);

#endif
