#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 

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

    void enqueue(int sID) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue more students." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        array[rear] = sID;
    }

    int count(int targetID) {
        int count = 0;

        if (isEmpty()) {
            return count;
        }

        int current = front;
        do {
            if (array[current] == targetID) {
                count++;
            }
            current = (current + 1) % capacity;
        } while (current != (rear + 1) % capacity);

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    Queue q(MAX_SIZE);

    for (int i = 0; i < n; ++i) {
        int sID;
        cin >> sID;
        q.enqueue(sID);
    }

    int targetID;
    cin >> targetID;

    int occurrences = q.count(targetID);

    cout << "Occurrences of " << targetID << " in the queue: " << occurrences << endl;

    return 0;
}
