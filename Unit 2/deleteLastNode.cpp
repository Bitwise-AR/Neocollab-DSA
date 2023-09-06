#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};
typedef struct Node Node;

Node* node(const string& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insert(Node*& head, const string& value) {
    Node* newNode = node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void remove(Node*& head) {
    if (head == nullptr) {
        return; 
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr; 
    } else {
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr; 
    }
}

void displayList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        string value;
        getline(cin, value);
        insert(head, value);
    }

    remove(head);
    displayList(head);
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}