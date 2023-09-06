#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* insertEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node* deleteSecondToLastNode(Node* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return head;
    }
    Node* current = head;
    while (current->next->next->next != nullptr) {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int size;
    cin >> size;
    Node* head = nullptr;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        head = insertEnd(head, value);
    }
    cout << "Original Linked List: ";
    printList(head);
    head = deleteSecondToLastNode(head);
    cout << "Updated Linked List: ";
    printList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
