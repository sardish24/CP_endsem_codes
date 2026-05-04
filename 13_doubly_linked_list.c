/*
 * Module: Linked Lists - part 2
 * Description: Demonstrates Doubly Linked List operations: node creation, 
 *              insertion (at head), forward traversal, and backward traversal.
 */

#include <stdio.h>
#include <stdlib.h>

/* 
 * Doubly Linked List Node
 * Contains data, a pointer to the next node, and a pointer to the previous node.
 */
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

/* 
 * Insert a node at the front of the list
 */
void push(struct Node **head_ref, int new_data) {
    /* 1. Allocate node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (!new_node) return;

    /* 2. Put in the data */
    new_node->data = new_data;

    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    /* 4. Change prev of head node to new node */
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }

    /* 5. Move the head to point to the new node */
    (*head_ref) = new_node;
}

/* 
 * Print list in both forward and backward directions
 */
void printList(struct Node *node) {
    struct Node *last;
    
    printf("\nTraversal in forward direction:\n");
    while (node != NULL) {
        printf("%d <-> ", node->data);
        last = node; /* Keep track of the last node for reverse traversal */
        node = node->next;
    }
    printf("NULL\n");

    printf("\nTraversal in reverse direction:\n");
    while (last != NULL) {
        printf("%d <-> ", last->data);
        last = last->prev; /* Move backwards using the prev pointer */
    }
    printf("NULL\n");
}

/* Free the memory allocated for the doubly linked list */
void freeList(struct Node **head_ref) {
    struct Node *current = *head_ref;
    struct Node *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head_ref = NULL;
}

int main() {
    /* Start with empty list */
    struct Node *head = NULL;

    push(&head, 40);
    push(&head, 30);
    push(&head, 20);
    push(&head, 10);

    printList(head);
    
    freeList(&head);

    return 0;
}
