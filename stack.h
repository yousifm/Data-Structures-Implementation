/*
Stack Implementation based on Linked-List Structure.
Assumes the very first node is a dummy node with no value,
with the actual stack starting at the second node.

The second node is considered the "top" of the stack
and any added elements are placed in that position,
becoming the node pointed at by the dummy.



[-]-> [1][2][3][4].....[n]
 ^     ^
dummy  top
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>

typedef struct node* node_ptr;
typedef struct node* STACK;

struct node {
    int data;
    node_ptr next;
};


int isempty(STACK stack) {
    return stack->next == NULL;
}

void add_element(STACK stack, int element) {
    node_ptr top_node;
    top_node = malloc(sizeof(struct node));
    
    top_node->next = stack->next;
    top_node->data = element;

    stack->next = top_node;
}

int pop_element(STACK stack) {
    if(stack->next == NULL) {
        fprintf(stderr, "POP ON EMPTY STACK");
        exit(-1);
    }

    int return_val = stack->next->data;
    node_ptr next_node = stack->next->next;
    
    free(stack->next);

    stack->next = next_node;

    return return_val;
}

int top_element(STACK stack) {
    if (isempty(stack)){
        fprintf(stderr, "TOP ON EMPTY STACK");
        exit(-1);
    }
    return stack->next->data;
}

STACK make_stack() {
    STACK stack;

    stack = malloc(sizeof(struct node));
    stack->next = NULL;
    
    return stack;
}

void make_empty(STACK stack) {
    node_ptr current_node, previous_node;
    
    if (isempty(stack)) return;

    current_node = stack->next;

    while (current_node != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
        free(previous_node);
    }
}