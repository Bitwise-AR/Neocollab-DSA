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
        Node* tail = (*head)->next; 
        while (tail->next != *head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = *head;
    }
}
void display(Node* head) {
    if (head == nullptr) {
        cout << "Linked List is empty." << endl;
        return;
    }

    Node* current = head;
    bool print = true;
    cout << "Alternate Nodes: ";
    do {
        if (print) {
            cout << current->data << " ";
        }
        print = !print;
        current = current->next;
    } while (current != head);

    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insert(&head, data);
    }

    display(head);

    return 0;
}
