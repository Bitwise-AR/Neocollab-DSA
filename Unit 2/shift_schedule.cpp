#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insert(Node* head, int data) {
    if (head == NULL)
        head = createNode(data);
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = createNode(data);
    }
    return head;
}

Node* lshift(Node* head, int k) {
    if (head == NULL || k == 0)
        return head;

    Node* current = head;
    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return head;

    Node* kthNode = current;
    while (current->next != NULL)
        current = current->next;

    current->next = head;
    head = kthNode->next;
    kthNode->next = NULL;

    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n;

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        head = insert(head, val);
    }
    cin >> k;
    cout << "Original Linked List: ";
    display(head);
    head = lshift(head, k);
    cout << "Modified Linked List after left shift: ";
    display(head);
    return 0;
}