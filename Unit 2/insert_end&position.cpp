#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }

    void insertAtPosition(int data, int position) {
        Node* newNode = new Node;
        newNode->data = data;

        if (position == 1 || head == nullptr) {
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            if (tail == nullptr) {
                tail = newNode;
            }
        } else {
            Node* current = head;
            int currentPosition = 1;
            while (currentPosition < position - 1 && current != nullptr) {
                current = current->next;
                currentPosition++;
            }

            if (current != nullptr) {
                newNode->next = current->next;
                newNode->prev = current;
                if (current->next != nullptr) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                if (current == tail) {
                    tail = newNode;
                }
            } else {
                cout << "Position is out of range." << endl;
                delete newNode;
            }
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList L;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        L.insertAtEnd(data);
    }

    int data, position;
    cin >> data >> position;
    cout << "List after inserting at the end: ";
    L.printList(); 
    L.insertAtPosition(data, position);
    cout << "List after inserting at position " << position << ": ";
    L.printList(); 

    return 0;
}
