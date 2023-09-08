#include <iostream>
using namespace std;
struct Node {
    int t_id;
    float t_amount;
    Node* next;
};

struct CircularLinkedList {
    Node* header;

    CircularLinkedList() {
        header = new Node;
        header->next = header;
    }

    void insert(int t_id, float t_amount) {
        Node* newNode = new Node;
        newNode->t_id = t_id;
        newNode->t_amount = t_amount;

        Node* current = header->next;
        Node* prev = header;
        while (current != header && current->t_id < t_id) {
            prev = current;
            current = current->next;
        }

        newNode->next = current;
        prev->next = newNode;
    }

    bool remove(int index) {
        Node* current = header;
        int currentIndex = -1;

        while (current->next != header && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }

        if (currentIndex != index - 1) {
            cout << "Invalid index." << endl;
            return false;
        }

        Node* deletedNode = current->next;
        current->next = deletedNode->next;
        delete deletedNode;
        return true;
    }

    void displayRecords() {
        Node* current = header->next;
        int index = 0;
        while (current != header) {
            cout << "Index " << index++ << ": Transaction ID: " << current->t_id << ", Amount: " << current->t_amount << endl;
            current = current->next;
        }
    }

    ~CircularLinkedList() {
        Node* current = header->next;
        while (current != header) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete header;
    }
};

int main() {
    CircularLinkedList t_list;
    int n;
    int t_id;
    float t_amount;
    int index;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t_id >> t_amount;
        t_list.insert(t_id, t_amount);
    }

    cin >> index;

    if (t_list.remove(index)) {
        cout << "Transaction record at index " << index << " has been successfully deleted." << endl;
        cout << "Updated transaction records:" << endl;
        t_list.displayRecords();
    }

    return 0;
}