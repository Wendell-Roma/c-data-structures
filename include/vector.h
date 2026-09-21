#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h> // biblioteca que da o tipo booleano
#include <stddef.h> // biblioteca que da o tipo size_t (que é apenas um numero interio sem sinal)

// A struct com 3 variaveis:
typedef struct vector {
  int *items;      // Ponteiro para o array de inteiros
  size_t size;     // Quantos itens temos guardados agora
  size_t capacity; // Capacidade total antes de precisar expandir
} vector_t;

// As primeiras funções que vamos criar juntos:
vector_t *vector_create(size_t initial_capacity);
void vector_destroy(vector_t *vec);

#endif // VECTOR_H
