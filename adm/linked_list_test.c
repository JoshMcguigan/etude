#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/linked_list.h"

typedef struct {
    int x, y;
} thing;

int main() {
    LinkedList s = linked_list_new();
    thing* t;

    t = (thing*) malloc(sizeof(thing));
    t->x = 1;
    t->y = 2;
    linked_list_push(&s, t);

    t = (thing *)malloc(sizeof(thing));
    t->x = 3;
    t->y = 4;
    linked_list_push(&s, t);

    t = (thing *)linked_list_pop(&s);
    assert(t->x == 3);
    assert(t->y == 4);
    free(t);

    t = (thing*) linked_list_pop(&s);
    assert(t->x == 1);
    assert(t->y == 2);
    free(t);

    t = (thing *)linked_list_pop(&s);
    assert(t == NULL);
}
