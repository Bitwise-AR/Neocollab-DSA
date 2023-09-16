#include <iostream>
using namespace std;

class Queue {
private:
    int capacity;
    int front;
    int rear;
    int* array;

public:
    Queue(int size) {
        capacity = size;
        front = rear = -1;
        array = new int[capacity];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int order) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more orders." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        array[rear] = order;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return array[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return array[rear];
    }
};

int main() {
    int capacity;
    cin >> capacity;

    Queue q(capacity);

    for (int i = 0; i < capacity; ++i) {
        int order;
        cin >> order;
        q.enqueue(order);
    }

    int front = q.getFront();
    int rear = q.getRear();

    if (front != -1 && rear != -1) {
        cout << "Front element: " << front << endl;
        cout << "Rear element: " << rear << endl;
    }

    return 0;
}
