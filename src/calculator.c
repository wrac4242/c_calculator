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
        printf("add, sub, mul, div, exit, top, or the number to add: ");
        char input[50];
        fgets(input, sizeof(input), stdin);
        printf("%s", input);
        if (!strcmp(input, "add\n")) {
            printf("+\n");
            int a = stackPop(head);
            int b = stackPop(head);
            stackPush(head, a+b);
        } else if (!strcmp(input, "sub\n")) {
            printf("-\n");
            int a = stackPop(head);
            int b = stackPop(head);
            stackPush(head, a-b);
        } else if (!strcmp(input, "mul\n")) {
            printf("*\n");
            int a = stackPop(head);
            int b = stackPop(head);
            stackPush(head, a*b);
        } else if (!strcmp(input, "div\n")) {
            printf("/\n");
            int a = stackPop(head);
            int b = stackPop(head);
            stackPush(head, a/b);
        } else if (!strcmp(input, "exit\n")) {
            printf("looping finished");
            looping = 0;
        } else if (!strcmp(input, "top\n")) {
            if (head == NULL) { 
                printf("error, value is not there\n"); 
            } else {
                printf("top of the stack: %i\n", head->value);
            }
        } else {
            printf("adding num\n");
            int num = atoi(input);
            stackPush(head, num);
        }
    }

    freeStack(head);
    
    return 0;
}
