#pragma once

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


node_ptr create_node(int element) {
    node_ptr new_node = malloc(sizeof(struct node));

    new_node->data = element;
    new_node->next = NULL;

    return new_node;
}


void add_element(LIST list, int element) {
    node_ptr previous_node;

    previous_node = list;
    
    list->data++;

    while (previous_node->next != NULL) {
        previous_node = previous_node->next;
    }

    previous_node->next = create_node(element);
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

    list->data--;

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
    LIST l = create_node(0);
    return l;
}


int list_get_size(LIST l) {
    return l->data;
}


short list_is_empty(LIST l) {
    return l->data == 0;
}


LIST copy_list(LIST l) {
    node_ptr current_node;
    LIST new_list = make_list();

    current_node = l;

    while (current_node->next != NULL) {
        current_node = current_node->next;
        add_element(new_list, current_node->data);
    }

    return new_list;
}


short list_equals(LIST one, LIST two) {

    node_ptr current_one;
    node_ptr current_two;

    current_one = one;
    current_two = two;


    if (list_get_size(one) != list_get_size(two))
        return 0;

    while (current_one->next != NULL) {
        current_one = current_one->next;
        current_two = current_two->next;

        if (one->data != two->data)
            return 0;
    }

    return 1;
}