#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(TreeNode* root, int& count, int k, int& result) {
    if (root == nullptr || count >= k) {
        return;
    }
    
    inOrderTraversal(root->left, count, k, result);
    count++;
    
    if (count == k) {
        result = root->val;
        return;
    }
    
    inOrderTraversal(root->right, count, k, result);
}

int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int result = -1;
    inOrderTraversal(root, count, k, result);
    return result;
}

int main() {
    TreeNode* root = nullptr;
    int value;
    while (cin >> value && value != -1) {
        TreeNode* newNode = new TreeNode(value);
        if (root == nullptr) {
            root = newNode;
        } else {
            TreeNode* current = root;
            while (true) {
                if (value < current->val) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = newNode;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }
    
    int k;
    cin >> k;
    
    int result = kthSmallest(root, k);
    cout << result << endl;
    
    return 0;
}
