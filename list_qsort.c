#include "list.h"
#include <stdlib.h>

#ifdef DEBUG
#include <stdio.h>
#endif

list_t* partition(list_t** istart, list_t* end) {
  list_t* pivot = *istart;
  list_t* np = pivot->next;
  list_t** iend;
  
#ifdef DEBUG
  printf("\t[partition start]\t");
  list_print(*istart, end);
#endif

  pivot->next = end;
  iend = &pivot->next;
  
  while (np != end) {
    list_t* nnp = np->next;
    if (np->data < pivot->data) {
      np->next = *istart;
      *istart = np;
    }
    else {
      np->next = *iend;
      *iend = np;
      iend = &np->next;
    }
    np = nnp;
  }

#ifdef DEBUG
  printf("\t[partition end]\t");
  list_print(*istart, end);
#endif

  return pivot;
}

void list_qsort_impl(list_t** istart, list_t* end) {
  if (*istart == end || (*istart)->next == end)
    return;
  
  list_t* pivot = partition(istart, end);
  list_qsort_impl(istart, pivot);
  list_qsort_impl(&pivot->next, end);

  return;
}

void list_qsort(list_t** ihead) {
  list_qsort_impl(ihead, NULL);
}
