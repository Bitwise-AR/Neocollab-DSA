#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int val;
    
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        root = insert(root, val);
    }

    cout << "Post order Traversal:" << endl;
    postorderTraversal(root);
    
    return 0;
}