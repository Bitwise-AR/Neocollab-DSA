#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

int kthSmallest(TreeNode* root, int k) {
    TreeNode* current = root;
    int count = 0;
    int kthSmallest = -1;

    while (current != NULL) {
        if(current->left == NULL) {
            count++;
            if (count == k) {
                kthSmallest = current->val;
            }
            current = current->right;
        } else {
            TreeNode* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
                predecessor->right = current;
                current = current->left;
            } else {
                predecessor->right = NULL;
                count++;
                if (count == k) {
                    kthSmallest = current->val;
                }
                current = current->right;
            }
        }
    }

    return kthSmallest;
}

int main() {
    TreeNode* root = NULL;
    int val;
    
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        root = insert(root, val);
    }
    
    int k;
    cin >> k;

    int kthSmallestValue = kthSmallest(root, k);
    cout << "Smallest kth value " << kthSmallestValue << endl;
    return 0;
}