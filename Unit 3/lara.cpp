#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void deleteMiddle() {
        if (size < 3) {
            cerr << "Cannot delete middle element in a list with less than 3 elements." << endl;
            return;
        }

        Node* slowPtr = head;
        Node* fastPtr = head;
        Node* prevSlow = nullptr;

        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            fastPtr = fastPtr->next->next;
            prevSlow = slowPtr;
            slowPtr = slowPtr->next;
        }

        prevSlow->next = slowPtr->next;
        delete slowPtr;
        size--;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    if (n % 2 != 1 || n < 3 || n > 51) {
        cerr << "Invalid input. n should be odd and within the range of 3 to 51." << endl;
        return 1;
    }

    LinkedList linkedList;

    for (int i = n; i >= 1; i--) {
        linkedList.push(i);
    }

    linkedList.deleteMiddle();
    linkedList.display();

    return 0;
}
