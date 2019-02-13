#pragma once

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

#include <stdlib.h>
#include <stdio.h>
#include "list.h"


typedef struct node* STACK;


int stack_isempty(STACK stack) {
    return stack->next == NULL;
}


void push_element(STACK stack, int element) {
    stack->data++;

    node_ptr top_node = create_node(element);
    top_node->next = stack->next;

    stack->next = top_node;
}


int top_element(STACK stack) {
    if (stack_isempty(stack)){
        fprintf(stderr, "TOP ON EMPTY STACK");
        exit(-1);
    }
    return stack->next->data;
}


void delete_top(STACK stack) {
    stack->data--;

    node_ptr next_node = stack->next->next;
    
    free(stack->next);

    stack->next = next_node;
}


int pop_element(STACK stack) {
    if(stack_isempty(stack)) {
        fprintf(stderr, "POP ON EMPTY STACK");
        exit(-1);
    }

    int return_val = top_element(stack);

    delete_top(stack);

    return return_val;
}


STACK make_stack() {
    STACK stack = create_node(0);
    
    return stack;
}


void make_empty(STACK stack) {
    node_ptr current_node, previous_node;
    
    if (stack_isempty(stack)) return;

    current_node = stack->next;

    while (current_node != NULL) {
        previous_node = current_node;
        current_node = current_node->next;
        free(previous_node);
    }
}


int stack_get_size(STACK stack) {
    return stack->data;
}


STACK copy_stack(STACK stack) {
    node_ptr current_node;
    //cheating, haha
    STACK new_stack = copy_list(stack);
    
    return new_stack;
}

