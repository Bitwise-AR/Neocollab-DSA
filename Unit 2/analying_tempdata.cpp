#include <iostream>
using namespace std;

struct Node {
    int temperature;
    Node* prev;
    Node* next;

    Node(int temp) : temperature(temp), prev(nullptr), next(nullptr) {}
};

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        current->prev = nextNode;
        prev = current;
        current = nextNode;
    }

    return prev; 
}

void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->temperature << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        Node* newNode = new Node(temp);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    head = reverse(head);
    cout << "Original List: ";
    display(head);
    head = reverse(head);
    cout << "Reversed List: ";
    display(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}