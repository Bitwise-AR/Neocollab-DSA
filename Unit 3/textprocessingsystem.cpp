#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Queue {
private:
    int front;
    int rear;
    vector<char> elements;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(char item) {
        elements.push_back(item);
        if (front == -1) {
            front = 0;
        }
        rear++;
    }

    char dequeue() {
        if (isEmpty()) {
            return '\0'; 
        }
        char item = elements[front];
        front++;
        return item;
    }

    bool isEmpty() {
        return front > rear;
    }
};

int unique(const string& input) {
    int count[26] = {0};  
    Queue queue;
    for (char ch : input) {
        count[ch - 'a']++;
        queue.enqueue(ch);
    }

    int index = 0;
    while (!queue.isEmpty()) {
        char ch = queue.dequeue();
        if (count[ch - 'a'] == 1) {
            return index;
        }
        index++;
    }

    return -1;  
}

int main() {
    string input;
    cin >> input; 
    int result = unique(input);
    cout << result << endl;

    return 0;
}