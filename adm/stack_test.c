#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/stack.h"

typedef struct {
    int x, y;
} thing;

int main() {
    stack s = stack_new();
    thing* t;

    t = (thing*) malloc(sizeof(thing));
    t->x = 1;
    t->y = 2;
    stack_push(&s, t);

    t = (thing *)malloc(sizeof(thing));
    t->x = 3;
    t->y = 4;
    stack_push(&s, t);

    t = (thing *)stack_pop(&s);
    assert(t->x == 3);
    assert(t->y == 4);

    t = (thing*) stack_pop(&s);
    assert(t->x == 1);
    assert(t->y == 2);

    t = (thing *)stack_pop(&s);
    assert(t == NULL);
}
