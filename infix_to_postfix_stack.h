#pragma once

#include <stdlib.h>
#include <string.h>
#include "stack.h"

unsigned short get_precedence(char operator) {
    switch (operator) {
    case '!':
        return 3;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        exit(-1);
    }
}

short precedence_cmp(const char op1, const char op2) {
    unsigned short op1_precedence, op2_precedence;

    op1_precedence = get_precedence(op1);
    op2_precedence = get_precedence(op2);
    
    return op1_precedence >= op2_precedence;
}

void infix_to_postfix (char infix[256], char postfix[256]) {
    char previous_operator, current_operator;
    char* substring;

    STACK operator_stack = make_stack();
    char* space = " ";

    strcpy(postfix, "\0");

    strtok(infix, "\n");
    substring = strtok(infix, space);

    while (substring != NULL) {
        if (atoi(substring) || strcmp(substring, "0") == 0) {
            strcat(postfix, substring);
            strcat(postfix, space);
        }
        else {
            current_operator = substring[0];
            
            while (!isempty(operator_stack)) {
                previous_operator = (char) top_element(operator_stack);

                if (precedence_cmp(previous_operator, current_operator)){
                    pop_element(operator_stack);
                    char addition[3] = {previous_operator, ' ', '\0'};

                    strcat(postfix, addition);
                }
                else {
                    break;
                }
            }
            add_element(operator_stack, (int) current_operator);
        }
        substring = strtok(NULL, space);
    }

    while (!isempty(operator_stack)) {
        current_operator = (char) pop_element(operator_stack);

        //current operator is the last element
        if (isempty(operator_stack)) {
            char addition[2] = {current_operator, '\0'};
            strcat(postfix, addition);
        }
        else {
            char addition[3] = {current_operator, ' ', '\0'};
            strcat(postfix, addition);
        }
    }
}
