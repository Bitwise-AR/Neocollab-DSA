#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertNode(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void displayList() {
        if (!head) {
            cout << "Linked List is empty." << endl;
        } else {
            cout << "Linked List: ";
            Node* current = head;
            while (current) {
                cout << current->data << ' ';
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    LinkedList l;
    int value;

    while (true) {
        cin >> value;
        if (value < 0) {
            break;
        }
        l.insertNode(value);
    }

    l.displayList();

    return 0;
}
