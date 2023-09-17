#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    void insertRear(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void displayEven() {
        Node* current = front;
        cout << "Even elements: ";
        while (current != nullptr) {
            if (current->data % 2 == 0) {
                cout << current->data << " ";
            }
            current = current->next;
        }
        cout << endl;
    }

    void displayOdd() {
        Node* current = front;
        cout << "Odd elements: ";
        while (current != nullptr) {
            if (current->data % 2 != 0) {
                cout << current->data << " ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    int element;
    cin >> element;

    while (element != -1) {
        dq.insertRear(element);
        cin >> element;
    }

    if (!dq.isEmpty()) {
        dq.displayEven();
        dq.displayOdd();
    }

    return 0;
}
