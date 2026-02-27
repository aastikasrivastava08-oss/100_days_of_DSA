#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to get length of linked list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move pointer of longer list ahead
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } else {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }

    // Compare nodes
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main() {
    int n, m, i, value;

    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *tail1 = NULL, *tail2 = NULL;

    scanf("%d", &n);

    // First list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    // Second list
    for (i = 0; i < m; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head2 == NULL) {
            head2 = tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    // 🔹 Manually creating intersection for testing (based on common values)
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;
    while (temp1 != NULL) {
        temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                tail2->next = temp1;   // Make intersection
                break;
            }
            temp2 = temp2->next;
        }
        if (temp2 != NULL)
            break;
        temp1 = temp1->next;
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}