#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class SortedLinkedList {
private:
    Node* head;

public:
    SortedLinkedList() : head(nullptr) {}
    void insertSorted(int value) {
        Node* newNode = new Node(value);

        if (!head || head->data >= value) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data < value) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    SortedLinkedList sortedList;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        sortedList.insertSorted(val);
    }
    int nlist;
    cin >> nlist;
    sortedList.insertSorted(nlist);
    sortedList.display();

    return 0;
}
