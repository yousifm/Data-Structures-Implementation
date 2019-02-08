#include "infix_to_postfix_stack.h"
#include <stdio.h>

int main () {
    char line[256];
    char postfix[256];
    char* fuck = "";

    fgets(line, 255, stdin);

    strcat(postfix, fuck);

    infix_to_postfix(line, postfix);
    printf("%s\n", postfix);
    return 0;
}