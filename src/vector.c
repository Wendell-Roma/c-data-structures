#include "../include/vector.h"
#include <stdbool.h>
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

bool vector_push_back(vector_t *vec, int item) {
  if (vec == NULL)
    return false;
  if (vec->size == vec->capacity) {
    int *new_items = realloc(vec->items, sizeof(int) * vec->capacity * 2);
    if (new_items == NULL)
      return false;
    vec->items = new_items;
    vec->capacity = vec->capacity * 2;
  }
  vec->items[vec->size] = item;
  vec->size++;
  return true;
}