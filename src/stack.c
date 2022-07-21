#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

node_t *createNode(int startingVal) {
	node_t *n = malloc(sizeof(node_t));
	n->next = NULL;
	n->value = startingVal;
	return n;
}

void stackPush(node_t *head, int toPush) {
	node_t *n = createNode(toPush);
	n->next = head;
	head = n;
}

int stackPop(node_t *head){ 
	if (head == NULL) { printf("error, value is not there, pop\n"); return 0; }
	int to_ret = head->value;
	node_t *old = head;
	head = old->next;
	free(old);
	return to_ret;
}

void freeStack(node_t *head) {
	node_t *node = head;
	while (node != NULL) {
		node_t *next = node->next;
		free(node);
		node = next;
	}
	head = NULL;
}
