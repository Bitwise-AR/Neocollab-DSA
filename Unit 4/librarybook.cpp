#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->val) {
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        root->right = insert(root->right, value);
    }
    return root;
}

TreeNode* findPredecessor(TreeNode* root, int value) {
    TreeNode* predecessor = nullptr;
    while (root != nullptr) {
        if (value < root->val) {
            root = root->left;
        } else if (value > root->val) {
            predecessor = root;
            root = root->right;
        } else {
            if (root->left != nullptr) {
                predecessor = root->left;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
            }
            break;
        }
    }
    return predecessor;
}

int main() {
    int N;
    cin >> N;

    TreeNode* root = nullptr;

    for (int i = 0; i < N; i++) {
        int bookID;
        cin >> bookID;
        root = insert(root, bookID);
    }

    int M;
    cin >> M;

    TreeNode* predecessor = findPredecessor(root, M);

    if (predecessor != nullptr) {
        cout << "Inorder Predecessor: " << predecessor->val << endl;
    } else {
        cout << "Doesn't exist" << endl;
    }

    return 0;
}