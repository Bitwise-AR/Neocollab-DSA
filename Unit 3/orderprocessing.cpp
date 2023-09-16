#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Queue {
private:
    int front;
    int rear;
    int queueArray[MAX_SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int orderID) {
        if (isFull()) {
            cout << "Queue is full." << endl;
        } else {
            if (isEmpty()) {
                front = 0;
            }
            rear = (rear + 1) % MAX_SIZE;
            queueArray[rear] = orderID;
            cout << "Order ID " << orderID << " is inserted in the queue." << endl;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        } else {
            int processedOrder = queueArray[front];
            if (front == rear) {
                front = rear = -1; 
            } else {
                front = (front + 1) % MAX_SIZE;
            }
            return processedOrder;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Order IDs in the queue are: ";
            int current = front;
            while (current != rear) {
                cout << queueArray[current] << " ";
                current = (current + 1) % MAX_SIZE;
            }
            cout << queueArray[rear] << endl;
        }
    }
};

int main() {
    Queue q;

    int option;
    while (cin >> option) {
        if (option == 1) {
            int orderID;
            cin >> orderID;
            q.enqueue(orderID);
        } else if (option == 2) {
            int processedOrder = q.dequeue();
            if (processedOrder != -1) {
                cout << "Processed Order ID: " << processedOrder << endl;
            }
        } else if (option == 3) {
            q.display();
        } else {
            cout << "Invalid option." << endl;
        }
    }

    return 0;
}
