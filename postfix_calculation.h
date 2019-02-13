#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

enum OPERATION_EXIT_CODE {OP_OK, OP_DIVISION_BY_ZERO,
                          OP_FACTORIAL_NEGATIVE, OP_INVALID};

int fact(int num) {
    int value = 1;
    while(num > 0) {
        value *= num;
        num--;
    }
    return value;
}

enum OPERATION_EXIT_CODE operate(STACK stack, char operator) {
    int op1, op2;
    int value;

    if (operator == '!') {
        op1 = pop_element(stack);
        if (op1 < 0) return OP_FACTORIAL_NEGATIVE;
        value = fact(op1);
    }
    else {
        if (stack_isempty(stack)) return OP_INVALID;
        op2 = pop_element(stack);
        if (stack_isempty(stack)) return OP_INVALID;
        op1 = pop_element(stack);

        switch (operator)
        {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '/':
                if (op2 == 0) return OP_DIVISION_BY_ZERO;
                value = op1 / op2;
                break;
            case '*':
                value = op1 * op2;
                break;
        }
    }

    add_element(stack, value);
    return OP_OK;
}

enum OPERATION_EXIT_CODE execute_operations(char line[256], int* result) {
    enum OPERATION_EXIT_CODE op_code;
    STACK stack = make_stack();
    char delim[] = " ";

    //splits the string by spaces
    char* ptr = strtok(line, delim);

    while (ptr != NULL){        
        if(atoi(ptr) || strcmp(ptr, "0") == 0) {
            add_element(stack, atoi(ptr));
        }
        else {
            op_code = operate(stack, *ptr);
            if (op_code != OP_OK) {
                break;
            }
        }
        ptr = strtok(NULL, delim);
    }

    if (op_code == OP_OK) {
        int r = pop_element(stack);
        if (!stack_isempty(stack)) return OP_INVALID;
        else {
            *result = r;
            return OP_OK;
        }
    }
    else {
        return op_code;
    }
}

void execute_operations_and_print(char line[256]) {
    enum OPERATION_EXIT_CODE err_code;
    int result;

    err_code = execute_operations(line, &result);
    switch(err_code) {
    case OP_INVALID:
        printf("invalid expression\n");
        break;
    case OP_FACTORIAL_NEGATIVE:
        printf("factorial of an negative number\n");
        break;
    case OP_DIVISION_BY_ZERO:
        printf("division by zero\n");
        break;
    case OP_OK:
        printf("%d\n", result);
        break;
    default:
        printf("Something's wrong.");
        exit(-1);
    }
}