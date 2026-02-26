#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Create new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct node* insertEnd(struct node* head, int value) {
    struct node* newNode = createNode(value);
    
    if (head == NULL)
        return newNode;
    
    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
    return head;
}

// Merge two sorted lists
struct node* mergeLists(struct node* head1, struct node* head2) {
    struct node* merged = NULL;
    struct node* temp = NULL;

    while (head1 != NULL && head2 != NULL) {
        struct node* newNode;

        if (head1->data <= head2->data) {
            newNode = createNode(head1->data);
            head1 = head1->next;
        } else {
            newNode = createNode(head2->data);
            head2 = head2->next;
        }

        if (merged == NULL) {
            merged = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Add remaining nodes
    while (head1 != NULL) {
        temp->next = createNode(head1->data);
        temp = temp->next;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        temp->next = createNode(head2->data);
        temp = temp->next;
        head2 = head2->next;
    }

    return merged;
}

int main() {
    int n, m, value;
    struct node *head1 = NULL, *head2 = NULL, *merged = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

    // Merge
    merged = mergeLists(head1, head2);

    // Print merged list
    struct node* temp = merged;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}