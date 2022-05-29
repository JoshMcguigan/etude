#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/vector.h"

typedef struct {
    int x, y;
} thing;

int main() {
    Vector s = vector_new();
    thing *t;

    t = (thing *)malloc(sizeof(thing));
    t->x = 1;
    t->y = 2;
    vector_push(&s, t);

    t = (thing *)malloc(sizeof(thing));
    t->x = 3;
    t->y = 4;
    vector_push(&s, t);

    t = (thing *)vector_pop(&s);
    assert(t != NULL);
    assert(t->x == 3);
    assert(t->y == 4);
    free(t);

    t = (thing *)vector_pop(&s);
    assert(t != NULL);
    assert(t->x == 1);
    assert(t->y == 2);
    free(t);

    t = (thing *)vector_pop(&s);
    assert(t == NULL);

    vector_free(&s);
}
