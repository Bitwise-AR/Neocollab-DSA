#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    
    cout << root->data << " ";
}

int calculateHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    int height = calculateHeight(root);
    cout << "Height of the tree: " << height - 1 << endl;

    return 0;
}
