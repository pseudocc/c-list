#include "list.h"
#include <stdlib.h>

#ifdef DEBUG
#include <stdio.h>
#endif

void list_invert(list_t** ihead) {
  list_t* curr = *ihead;
  while (curr->next) {
    list_t* next = curr->next;
    curr->next = next->next;
    next->next = *ihead;
    *ihead = next;
  }
}