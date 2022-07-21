#ifndef STACK
#define STACK

struct node  {
    int value;
    struct node* next;
};

typedef struct node node_t;

node_t *createNode(int startingVal);
void stackPush(node_t **head, int toPush);
int stackPop(node_t **head);
void freeStack(node_t **head);

#endif
