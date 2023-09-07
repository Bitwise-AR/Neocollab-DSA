#include <iostream>
using namespace std;
struct Node {
    char data;
    Node* next;
};

class GroundedHeaderLinkedList {
private:
    Node* head;
    int length;

public:
    GroundedHeaderLinkedList() {
        head = new Node();
        head->next = nullptr;
        length = 0;
    }

    void insert(int index, char inp) {
        if (index < 0 || index > length) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = inp;

        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        ++length;
    }

    void display() {
        Node* current = head->next;
        cout << "Updated list: ";
        while (current != nullptr) {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    GroundedHeaderLinkedList ll;
    char inp;
    for (int i = 0; i < n; ++i) {
        cin >> inp;
        ll.insert(i, inp);
    }
    int index;
    cin >> index;
    cin >> inp;
    ll.insert(index, inp);
    ll.display();

    return 0;
}