#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    bool dequeue() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return false;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
        return true;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* current = front;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int N;
    cin >> N;

    Queue q;

    for (int i = 0; i < N; i++) {
        int element;
        cin >> element;
        q.enqueue(element);
    }

    bool success = q.dequeue();

    if (success) {
        q.printQueue();
    }

    return 0;
}
