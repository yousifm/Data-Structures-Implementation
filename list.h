/*
Linked list and stuff.
Does list stuff!
First element is a dummy
*/



#include <stdlib.h>

typedef struct node* node_ptr;
typedef struct node* LIST;

struct node {
    int data;
    node_ptr next;
};

void add_element(LIST list, int element) {
    node_ptr previous_node;
    
    previous_node = list;

    while (previous_node->next != NULL) {
        previous_node = previous_node->next;
    }

    previous_node->next = malloc(sizeof(struct node));
    previous_node->next->data = element;
    previous_node->next->next = NULL;
}

void print_all(LIST list) {
    if (list->next == NULL) {
        printf("Empty List");
        return;
    }

    node_ptr current_node;
    current_node = list;
    while(current_node->next != NULL) {
        current_node = current_node->next;
        printf("%d\n", current_node->data);
    }
}

void delete_number(LIST list, int number) {
    node_ptr current_node, previous_node;
    previous_node = list;

    while (previous_node->next != NULL) {
        current_node = previous_node->next;
        if(current_node->data == number) {
            previous_node->next = current_node->next;
            free(current_node);
        }
        else {
            previous_node = current_node;
        }
    }
}

node_ptr find_number(LIST list, int number) {
    while(list->next != NULL) {
        list = list->next;
        if (list->data == number)
            return list;
    }
    return NULL;
}

void delete_node(LIST list, node_ptr node) {
    node_ptr current_node, previous_node;

    previous_node = list;

    while(previous_node->next != NULL) {
        current_node = previous_node->next;

        if(current_node == node) {
            previous_node->next = current_node->next;
            free(current_node);
            return;
        }

        previous_node = current_node;
    }
}

LIST make_list() {
    LIST l;
    l = malloc(sizeof(struct node));
    l->data = 0;
    l->next = NULL;
    return l;
}