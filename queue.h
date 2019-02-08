#include <stdlib.h>
#include <stdio.h>

typedef struct node* node_ptr;
typedef struct queue* QUEUE;

struct node {
    int data;
    node_ptr next;
};

struct queue {
    node_ptr first;
    node_ptr last;
};

node_ptr create_node(int number){
    node_ptr new_node = malloc(sizeof(struct node));

    new_node->data = number;
    new_node->next = NULL;

    return new_node;
}

QUEUE make_queue() {
    QUEUE q = malloc(sizeof(struct queue));
    q->first = NULL;
    q->last  = NULL;
    return q;
}

int is_empty(QUEUE q) {
    return q->first == NULL;
}

void enqueue(QUEUE q, int number) {
    node_ptr new_node = create_node(number);
    if (is_empty(q)) {
        q->first = new_node;
        q->last  = new_node;
    }
    else {
        q->last->next = new_node;
        q->last       = new_node;
    }
}

int dequeue(QUEUE q) {
    if (is_empty(q)) {
        fprintf(stderr, "ERROR: DEQUEUE ON AN EMPTY QUEUE");    
        exit(1);
    }
    else {
        int return_value;
        node_ptr temp;

        return_value = q->first->data;
        temp = q->first;

        q->first = q->first->next;
        free(temp);
        
        return return_value; 
    }
}
