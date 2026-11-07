#include "include/vector.h"
#include <stdio.h>

int main(void) {
  printf("=== Testando Vetor do Zero! ===\n");

  vector_t *v = vector_create(5);
  if (v == NULL) {
    printf("Falha ao alocar vetor na memoria!\n");
    return 1;
  }

  printf("Vetor criado no Heap com sucesso!\n");
  printf("Tamanho: %zu\n", v->size);
  printf("Capacidade: %zu\n", v->capacity);

  for (int i = 0; i < 6; i++) {
    vector_push_back(v, 10);
  }
  printf("Tamanho: %zu\n", v->size);
  printf("Capacidade: %zu\n", v->capacity);

  vector_destroy(v);
  printf("Memoria liberada com sucesso!\n");

  return 0;
}
