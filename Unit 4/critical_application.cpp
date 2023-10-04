#include <iostream>
#include <climits>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

bool isBST(TreeNode* root, long long minVal, long long maxVal) {
    if (root == nullptr) {
        return true;
    }
    
    if (root->val <= minVal || root->val >= maxVal) {
        return false;
    }
    
    return isBST(root->left, minVal, root->val) && isBST(root->right, root->val, maxVal);
}

bool isBST(TreeNode* root) {
    return isBST(root, LLONG_MIN, LLONG_MAX);
}

TreeNode* buildTree() {
    int rootVal;
    cin >> rootVal;

    if (rootVal == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(rootVal);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main() {
    TreeNode* root = buildTree();

    if (isBST(root)) {
        cout << "The given binary tree is a BST" << endl;
    } else {
        cout << "The given binary tree is not a BST" << endl;
    }
    
    return 0;
}
