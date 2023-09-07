#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node** headRef, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (*headRef == nullptr) {
        *headRef = newNode;
        newNode->next = *headRef;
        return;
    }

    Node* temp = *headRef;
    while (temp->next != *headRef) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *headRef;
}

bool isSorted(Node* head) {
    if (head == nullptr) {
        return true; 
    }

    Node* current = head;
    do {
        if (current->data > current->next->data) {
            return false;
        }
        current = current->next;
    } while (current->next != head);

    return true;
}

int main() {
    Node* head = nullptr;
    int n, data;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        append(&head, data);
    }

    if (isSorted(head)) {
        cout << "The list is sorted in non-decreasing order." << endl;
    } else {
        cout << "The list is not sorted in non-decreasing order." << endl;
    }

    return 0;
}