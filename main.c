#include "list.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define N 11
static void shuffle(int* data) {
  data[0] = 0;
  for (int i = 1; i < N; i++) {
    int j = rand() % i;
    data[i] = data[j];
    data[j] = i;
  }
}

int main() {
  int data[N];
  list_t* list = NULL;

  time_t t;
  #ifdef SEED
    t = (time_t)SEED;
  #else
    time(&t);
  #endif
  srand((unsigned)t);
  printf("random seed: %d\n", (unsigned)t);
  shuffle(data);

  for (int i = 0; i < N; i++)
    list_push(&list, data[i]);
  list_print(list, NULL);

  list_qsort(&list);
  puts("=>");
  list_print(list, NULL);

  list_free(&list);
  list_print(list, NULL);

  return 0;
}
