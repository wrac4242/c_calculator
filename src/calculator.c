#include <stdio.h>
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
    float a, b;
    printf("Please Enter your two floats in the format 'a b': ");
    scanf("%f %f", &a, &b);
    printf("add+, sub-, mul*, div/: ");

    char input[50];
    __fpurge(stdin);
    fgets(input, sizeof(input), stdin);

    if (strcmp(input, "add")) {
        printf("%f", a+b);
    } else if (strcmp(input, "sub")) {
        printf("%f", a-b);
    } else if (strcmp(input, "mul")) {
        printf("%f", a*b);
    } else if (strcmp(input, "div")) {
        printf("%f", a/b);
    } else {
        printf("not valid");
    }
    
    return 0;
}
