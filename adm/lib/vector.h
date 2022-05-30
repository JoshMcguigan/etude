#include <stdlib.h>

typedef struct {
    void **items;
    size_t length, capacity;
} Vector;

Vector vector_new();

size_t vector_length(Vector *vector);

void vector_push(Vector *vector, void *item);

void *vector_peek(Vector *vector);

void *vector_pop(Vector *vector);

void vector_free(Vector *vector);
