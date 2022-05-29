#include <stdlib.h>
#include <string.h>

#include "vector.h"

Vector vector_new() {
    return (Vector){.items = NULL, .length = 0, .capacity = 0};
}

void vector_push(Vector *vector, void *item) {
    if (vector->length >= vector->capacity) {
        size_t new_capacity;
        if (vector->capacity) {
            new_capacity = vector->capacity * 2;
        } else {
            new_capacity = 1;
        }

        vector->items = realloc(vector->items, new_capacity * sizeof(void *));

        vector->capacity = new_capacity;
    }

    *(vector->items + vector->length) = item;
    vector->length++;
}

void *vector_pop(Vector *vector) {
    if (!vector->length) {
        return NULL;
    }

    vector->length--;
    void *item = *(vector->items + vector->length);
    return item;
}

void vector_free(Vector *vector) {
    free(vector->items);

    vector->length = 0;
    vector->capacity = 0;
    vector->items = NULL;
}
