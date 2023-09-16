#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
};

void initialize(Stack* stack) {
    stack->top = nullptr;
}

bool isEmpty(Stack* stack) {
    return stack->top == nullptr;
}

void push(Stack* stack, int data) {
    Node* newNode = new Node;
    if (newNode == nullptr) {
        cout << "Memory allocation failed." << endl;
        exit(1);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack) {
    if (!isEmpty(stack)) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        delete temp;
    }
}

void deleteEven(Stack* stack) {
    Node* current = stack->top;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data % 2 == 0) {
            if (prev == nullptr) {
                Node* temp = current;
                current = current->next;
                stack->top = current;
                delete temp;
            } else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void display(Stack* stack) {
    Node* current = stack->top;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Stack stack;
    initialize(&stack);
    int n, element;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> element;
        push(&stack, element);
    }

    display(&stack);
    deleteEven(&stack);
    display(&stack);

    return 0;
}
