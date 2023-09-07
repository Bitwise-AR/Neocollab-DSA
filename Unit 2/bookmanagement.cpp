#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* create(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void display(Node* head) {
    Node* current = head->next;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void remove(Node* head, int position) {
    if (position < 1) {
        cout << "Invalid position." << endl;
        return;
    }

    Node* prev = head;
    Node* current = head->next;
    int count = 1;

    while (current != nullptr && count < position) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Position out of range." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
}

int main() {
    int n;
    cin >> n;
    Node* head = create(0);
    Node* tail = head;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        tail->next = create(value);
        tail = tail->next;
    }

    while (true) {
        int position;
        cin >> position;
        if (position == 0) {
            break;
        }
        cout << "Linked List before deletion: ";
        display(head);

        remove(head, position);

        cout << "Linked List after deletion: ";
        display(head);
        
        break;
    }

    Node* current = head->next;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;

    return 0;
}
