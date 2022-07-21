#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "stack.h"
/* 
    TODO:
    basic calculator
    stack setup
    polish calculator 

    stack just adds stuff to the head
*/


int main() {

    int looping = 1;
    node_t *head = NULL;

    while (looping) {
        printf("add, sub, mul, div, exit, peak, swap, pop, or the number to add: ");
        char input[50];
        fgets(input, sizeof(input), stdin);
        if (!strcmp(input, "add\n")) {
            int a = stackPop(&head);
            int b = stackPop(&head);
            stackPush(&head, a+b);
        } else if (!strcmp(input, "sub\n")) {
            int a = stackPop(&head);
            int b = stackPop(&head);
            stackPush(&head, a-b);
        } else if (!strcmp(input, "mul\n")) {
            int a = stackPop(&head);
            int b = stackPop(&head);
            stackPush(&head, a*b);
        } else if (!strcmp(input, "div\n")) {
            int a = stackPop(&head);
            int b = stackPop(&head);
            stackPush(&head, a/b);
        } else if (!strcmp(input, "exit\n")) {
            looping = 0;
        } else if (!strcmp(input, "peak\n")) {
            if (head == NULL) { 
                printf("error, value is not there\n"); 
            } else {
                printf("top of the stack: %i\n", head->value);
            }
        } else if (!strcmp(input, "swap\n")) {
            int a = stackPop(&head);
            int b = stackPop(&head);
            stackPush(&head, a);
            stackPush(&head, b);
        } else if (!strcmp(input, "pop\n")) {
            printf("popped off: %i\n", stackPop(&head));
        } else {
            int num = atoi(input);
            stackPush(&head, num);
        }
    } 
    freeStack(&head);
    
    return 0;
}
