#include <stdlib.h>

#include "linked_list.h"

LinkedList linked_list_new() { return (LinkedList){NULL}; }

void linked_list_push(LinkedList *linked_list, void *item) {
    LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    node->data = item;
    node->next = linked_list->next;

    linked_list->next = node;
}

void *linked_list_pop(LinkedList *linked_list) {
    LinkedListNode *next_node = linked_list->next;

    if (next_node != NULL) {
        linked_list->next = next_node->next;

        void *ret = next_node->data;

        free(next_node);

        return ret;
    } else {
        return NULL;
    }
}

void linked_list_reverse(LinkedList *linked_list) {
    LinkedListNode *previous_node = NULL;
    LinkedListNode *current_node = linked_list->next;

    while (current_node != NULL) {
        LinkedListNode *next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }

    linked_list->next = previous_node;
}
