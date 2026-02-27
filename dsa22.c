#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *current = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        temp = createNode(value);

        if(head == NULL) {
            head = temp;
        } else {
            current->next = temp;
        }
        current = temp;
    }

    // Print linked list
    current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}