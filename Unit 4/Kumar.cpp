#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    
    BST() : root(nullptr) {}
    
    void insert(int value) {
        root = insertRecursive(root, value);
    }
    
    void inorderTraversal() {
        inorderTraversalRecursive(root);
    }
    
private:
    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) {
            return new Node(value);
        }
        
        if (value <= current->data) {
            current->left = insertRecursive(current->left, value);
        } else {
            current->right = insertRecursive(current->right, value);
        }
        
        return current;
    }
    
    void inorderTraversalRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }
        
        inorderTraversalRecursive(current->left);
        cout << current->data << " ";
        inorderTraversalRecursive(current->right);
    }
};

int main() {
    BST bst;
    int num;
    
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        
        bst.insert(num);
    }
    
    bst.inorderTraversal();
    
    return 0;
}
