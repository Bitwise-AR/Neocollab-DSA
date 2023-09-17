
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class PriorityQueue {
private:
    int elements[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void enqueue(int element, int priority) {
        if (size >= MAX_SIZE) {
            cout << "Priority Queue is full." << endl;
            return;
        }

        int index = size;
        while (index > 0 && priority < priorities[index - 1]) {
            elements[index] = elements[index - 1];
            priorities[index] = priorities[index - 1];
            index--;
        }

        elements[index] = element;
        priorities[index] = priority;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        for (int i = 0; i < size - 1; i++) {
            elements[i] = elements[i + 1];
            priorities[i] = priorities[i + 1];
        }

        size--;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    void printPriorityQueue() {
        for (int i = 0; i < size; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int N;
    cin >> N;

    PriorityQueue priorityQueue;

    for (int i = 0; i < N; i++) {
        int element, priority;
        cin >> element >> priority;
        priorityQueue.enqueue(element, priority);
    }

    cout << "Priority Queue: ";
    priorityQueue.printPriorityQueue();

    priorityQueue.dequeue();

    cout << "Priority Queue: ";
    priorityQueue.printPriorityQueue();

    return 0;
}
