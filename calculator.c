#include "infix_to_postfix_stack.h"
#include "postfix_calculation.h"
#include <stdio.h>

int main () {
    char infix[256];
    char postfix[256];
    int result;

    printf("Input expression: \n");
    fgets(infix, 256, stdin);

    infix_to_postfix(infix, postfix);
    execute_operations_and_print(postfix);
}