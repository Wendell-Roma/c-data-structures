#include "../include/vector.h"
#include <stdlib.h> // biblioteca que da acesso ao malloc e free

vector_t *vector_create(size_t initial_capacity) {

  vector_t *vec = (vector_t *)malloc(sizeof(vector_t));
  if (vec == NULL)
    return NULL; // se a memoria não acabou

  size_t cap = (initial_capacity > 0) ? initial_capacity : 4;

  vec->items = (int *)malloc(sizeof(int) * cap);
  if (vec->items == NULL) {
    free(vec); // Limpeza de segurança para não vazar a struct
    return NULL;
  }
  vec->size = 0;
  vec->capacity = cap;

  return vec;
}

void vector_destroy(vector_t *vec) {
  if (vec == NULL)
    return;
  free(vec->items);
  free(vec);
}