#include <stdlib.h>
#include <stdio.h>

typedef struct tree_node* tree_node_ptr;
typedef struct bst* BST;

struct tree_node {
    int data;
    tree_node_ptr left;
    tree_node_ptr right;
};

struct bst {
    tree_node_ptr head;
};

BST create_tree() {
    BST t;
    t = malloc(sizeof(struct bst));
    
    t->head = NULL;
    return t;
}

void add_element(BST tree, int element) {
    tree_node_ptr head_node, new_node;

    head_node = tree->head;

    new_node = malloc(sizeof(struct tree_node));
    new_node->data  = element;
    new_node->right = NULL;
    new_node->left  = NULL;

    if (head_node == NULL) {
        tree->head = new_node;
        return;
    }
    
    //ELSE
    while (1) {
        if (element <= head_node->data) {
            if(head_node->left == NULL) {
                head_node->left = new_node;
                return;
            }
            else {
                head_node = head_node->left;
            }
        }
        else {
            if(head_node->right == NULL) {
                head_node->right = new_node;
                return;
            }
            else {
                head_node = head_node->right;
            }
        }
    }
}

void __print_all(tree_node_ptr node) {
    if (node != NULL) {
        __print_all(node->left);
        printf("%d\n", node->data);
        __print_all(node->right);
    }
}

void print_all(BST t) {
    __print_all(t->head);
}