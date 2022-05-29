typedef struct stack_node {
  void *data;
  struct stack_node *next;
} stack_node;

typedef struct {
  stack_node *next;
} stack;

stack stack_new();

void stack_push(stack* s, void* item);

void *stack_pop(stack *s);
