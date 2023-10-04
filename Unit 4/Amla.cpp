#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int bookID) {
    if (root == nullptr) {
        return new Node(bookID);
    }
    if (bookID < root->data) {
        root->left = insert(root->left, bookID);
    } else if (bookID > root->data) {
        root->right = insert(root->right, bookID);
    }
    return root;
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    int N;
    cin >> N;

    Node* root = nullptr;

    for (int i = 0; i < N; i++) {
        int bookID;
        cin >> bookID;
        root = insert(root, bookID);
    }

    inOrder(root);

    return 0;
}
