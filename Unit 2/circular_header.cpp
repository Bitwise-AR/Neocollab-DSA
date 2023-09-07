#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* create(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = create(data);

    if (*head == nullptr) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
    }
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "Linked List is empty." << endl;
        return;
    }

    Node* current = head;

    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

    cout << endl;
}

int main() {
    int n, data;
    Node* head = nullptr;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        insert(&head, data);
    }

    displayList(head);

    return 0;
}
