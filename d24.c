#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node {
    int data;
    struct node* next;
};

// Create new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, value, key, i;
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    
    // Input number of nodes
    scanf("%d", &n);
    
    // Create linked list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    
    // Input key
    scanf("%d", &key);
    
    // Delete first occurrence
    struct node *current = head, *previous = NULL;
    
    // Case 1: If head itself contains key
    if (current != NULL && current->data == key) {
        head = current->next;
        free(current);
    } else {
        // Traverse to find key
        while (current != NULL && current->data != key) {
            previous = current;
            current = current->next;
        }
        
        // If key found
        if (current != NULL) {
            previous->next = current->next;
            free(current);
        }
    }
    
    // Print updated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    
    return 0;
}