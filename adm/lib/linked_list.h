typedef struct LinkedListNode {
    void *data;
    struct LinkedListNode *next;
} LinkedListNode;

typedef struct {
    LinkedListNode *next;
} LinkedList;

LinkedList linked_list_new();

void linked_list_push(LinkedList *s, void *item);

void *linked_list_pop(LinkedList *s);
