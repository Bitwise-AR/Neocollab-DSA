#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}
vector<int> linkedListToVector(Node* head) {
    vector<int> sortedList;
    while (head) {
        sortedList.push_back(head->data);
        head = head->next;
    }
    sort(sortedList.begin(), sortedList.end());
    return sortedList;
}

Node* findUnion(Node* list1, Node* list2) {
    set<int> unionSet;
    while (list1) {
        unionSet.insert(list1->data);
        list1 = list1->next;
    }
    while (list2) {
        unionSet.insert(list2->data);
        list2 = list2->next;
    }
    Node* unionList = nullptr;
    for (int val : unionSet) {
        insert(unionList, val);
    }
    
    return unionList;
}
void printSorted(Node* head) {
    set<int> sortedSet;
    while (head) {
        sortedSet.insert(head->data);
        head = head->next;
    }
    for (int val : sortedSet) {
        cout << val << " ";
    }
    cout << endl;
}
int main() {
    int n, m;
    cin >> n;
    Node* list1 = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(list1, val);
    }
    
    cin >> m;
    Node* list2 = nullptr;
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        insert(list2, val);
    }
    
    vector<int> sortedList1 = linkedListToVector(list1);
    vector<int> sortedList2 = linkedListToVector(list2);
    
    cout << "First Linked List: ";
    for (int val : sortedList1) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "Second Linked List: ";
    for (int val : sortedList2) {
        cout << val << " ";
    }
    cout << endl;
    Node* unionList = findUnion(list1, list2);
    cout << "Union Linked List: ";
    printSorted(unionList);
    cout << endl;
    
    return 0;
}
