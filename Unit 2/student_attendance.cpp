#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteOccurrences(Node** head, int value) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            Node* temp = current;
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n, deleteValue;
    scanf("%d", &n);
    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    scanf("%d", &deleteValue);

    printf("Original List: ");
    displayList(head);

    deleteOccurrences(&head, deleteValue);

    printf("List after deleting all occurrences of %d: ", deleteValue);
    displayList(head);

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
