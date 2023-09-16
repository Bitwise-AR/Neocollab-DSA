#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            exit(0);
        } else {
            Node* temp = top;
            int poppedData = top->data;
            top = top->next;
            delete temp;
            return poppedData;
        }
    }

    int getTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            exit(0);
        } else {
            return top->data;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            exit(0);
        } else {
            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    Stack stack;

    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        stack.push(element);
    }

    stack.display();
    cout << "Top element is " << stack.getTop() << endl;

    stack.pop();

    stack.display();
    cout << "Top element is " << stack.getTop() << endl;

    return 0;
}