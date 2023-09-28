#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasDuplicateCustomerIDs(TreeNode* root, unordered_set<int>& customerIDs) {
    if (!root) {
        return false; 
    }

    if (customerIDs.find(root->val) != customerIDs.end()) {
        return true; 
    }
    customerIDs.insert(root->val);

    if (hasDuplicateCustomerIDs(root->left, customerIDs) || hasDuplicateCustomerIDs(root->right, customerIDs)) {
        return true;
    }

    return false;
}

int main() {
    int rootValue;
    cin >> rootValue;

    TreeNode* root = new TreeNode(rootValue);

    while (true) {
        int leftChild, rightChild;
        cin >> leftChild;
        cin >> rightChild;
        if (leftChild == -1 && rightChild == -1) {
            break;
        }

        TreeNode* current = root;
        while (current) {
            if (leftChild < current->val) {
                if (current->left == NULL) {
                    current->left = new TreeNode(leftChild);
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = new TreeNode(leftChild);
                    break;
                } else {
                    current = current->right;
                }
            }
        }

        current = root;
        while (current) {
            if (rightChild < current->val) {
                if (current->left == NULL) {
                    current->left = new TreeNode(rightChild);
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = new TreeNode(rightChild);
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }

    unordered_set<int> customerIDs;

    if (hasDuplicateCustomerIDs(root, customerIDs)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
