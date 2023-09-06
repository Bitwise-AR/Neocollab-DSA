#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayList(struct Node* head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int numElements;
    cin >> numElements;

    struct Node* head = NULL;

    for (int i = 0; i < numElements; i++) {
        int element;
        cin >> element;
        insertNode(&head, element);
    }

    displayList(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}