/*
 * Module: Linked Lists - part 1
 * Description: Demonstrates Singly Linked List operations: creation, insertion 
 *              (at head), traversal, and memory cleanup (deletion).
 */

#include <stdio.h>
#include <stdlib.h>

/* 
 * Node Definition
 * A linked list node contains data and a pointer to the next node.
 */
struct Node {
    int data;
    struct Node *next; /* Self-referential structure */
};

/* 
 * Function to insert a new node at the beginning (Head) of the list.
 * We pass a pointer to the head pointer (struct Node **) so we can modify 
 * the actual head pointer in main.
 */
void insertAtHead(struct Node **head_ref, int new_data) {
    /* 1. Allocate memory for new node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    /* 2. Put in the data */
    new_node->data = new_data;

    /* 3. Make next of new node as head */
    new_node->next = *head_ref;

    /* 4. Move the head to point to the new node */
    *head_ref = new_node;
}

/* 
 * Function to print the linked list
 */
void printList(struct Node *node) {
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next; /* Move to the next node */
    }
    printf("NULL\n");
}

/* 
 * Function to free all nodes to prevent memory leaks
 */
void freeList(struct Node **head_ref) {
    struct Node *current = *head_ref;
    struct Node *next_node;

    while (current != NULL) {
        next_node = current->next; /* Save the next pointer */
        free(current);             /* Free the current node */
        current = next_node;       /* Advance to next node */
    }
    *head_ref = NULL; /* Set head to NULL */
}

int main() {
    /* Start with the empty list */
    struct Node *head = NULL;

    /* Insert elements */
    insertAtHead(&head, 30);
    insertAtHead(&head, 20);
    insertAtHead(&head, 10);

    /* Print the list */
    printList(head);

    /* Clean up memory */
    freeList(&head);
    printf("List memory freed.\n");

    return 0;
}
