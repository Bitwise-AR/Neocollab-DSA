#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void deleteNode(Node* head, int value) {
    Node* curr = head->next;
    Node* prev = head;
    while (curr != nullptr) {
        if (curr->data == value) {
            prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
}

int main() {
    Node* head = new Node();
    head->next = nullptr;
    int value;
    while (cin >> value && value != -1) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head->next;
        head->next = newNode;
    }
    while (cin >> value && value != -1) {
        deleteNode(head, value);
    }

    Node* current = head->next;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}