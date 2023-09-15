#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow. Cannot push more elements." << endl;
            return;
        }
        arr[++top] = value;
        cout << "Element " << value << " pushed onto the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow. Cannot perform pop operation." << endl;
            return;
        }
        int poppedValue = arr[top--];
        cout << "Element " << poppedValue << " popped from the stack." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Elements in the stack:";
        for (int i = top; i <= 0; i--) {
            cout << " " << arr[i];
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    int choice, value;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.display();
                break;

            case 4:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }

    return 0;
}
