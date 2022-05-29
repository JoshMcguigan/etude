#include <stdlib.h>

#include "stack.h"

stack stack_new() {
    return (stack){ NULL };
}

void stack_push(stack *s, void *item) {
    stack_node* n = (stack_node*) malloc(sizeof(stack_node));
    n->data = item;
    n->next = s->next;

    s->next = n;
}

void *stack_pop(stack *s) {
    stack_node *ret = s->next;

    if (ret != NULL) {
        s->next = ret->next;

        return ret->data;
    } else {
        return NULL;
    }
}
