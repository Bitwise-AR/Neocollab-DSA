#include <iostream>
using namespace std;

#define MAX_SIZE 10

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initialize(Stack* s) {
    s->top = -1;
}

bool isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int element) {
    if (!isFull(s)) {
        s->arr[++s->top] = element;
    }
}

void pop(Stack* s) {
    if (!isEmpty(s)) {
        s->top--;
    } else {
        cout << "Stack is empty" << endl;
    }
}

void getMax(Stack* s) {
    if (!isEmpty(s)) {
        int max = s->arr[0];
        for (int i = 1; i <= s->top; i++) {
            if (s->arr[i] > max) {
                max = s->arr[i];
            }
        }
        cout << "Maximum element: " << max << endl;
    } else {
        cout << "Maximum element: -1" << endl;
    }
}

void display(Stack* s) {
    if (!isEmpty(s)) {
        for (int i = 0; i <= s->top; i++) {
            cout << s->arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack is empty" << endl;
    }
}

int main() {
    Stack s;
    initialize(&s);
    int choice, element;

    while (true) {
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> element;
                push(&s, element);
                break;

            case 2:
                pop(&s);
                break;

            case 3:
                getMax(&s);
                break;

            case 4:
                display(&s);
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
