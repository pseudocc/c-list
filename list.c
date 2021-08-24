#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void list_push(list_t** ihead, int data) {
  if (ihead == NULL)
    return;
  
  list_t* node = malloc(sizeof(list_t));
  node->next = *ihead;
  node->data = data;

  *ihead = node;
}

int list_pop(list_t** ihead) {
  if (ihead == NULL || *ihead == NULL)
    return -1;
  
  list_t* node = *ihead;
  int data = node->data;
  *ihead = node->next;
  free(node);

  return data;
}

void list_free(list_t** ihead) {
  if (ihead == NULL || *ihead == NULL)
    return;
  
  while (*ihead != NULL) {
    list_t* node = *ihead;
    *ihead = node->next;
    free(node);
  }
}

void list_print(list_t* head, list_t* end) {
  printf("[ ");
  
  while (head != NULL) {
    if (head->next == end) {
      printf("%d", head->data);
      break;
    }
    printf("%d, ", head->data);
    head = head->next;
  }
  
  printf(" ]\n");
  return;
}
