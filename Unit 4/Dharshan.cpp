#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructBinaryTree(vector<int>& arr, int index, int n) {
    if (index >= n || arr[index] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[index]);
    root->left = constructBinaryTree(arr, 2 * index + 1, n);
    root->right = constructBinaryTree(arr, 2 * index + 2, n);

    return root;
}

void postOrderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left, result);
    postOrderTraversal(root->right, result);
    result.push_back(root->val);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    TreeNode* root = constructBinaryTree(arr, 0, n);

    vector<int> postOrderResult;
    postOrderTraversal(root, postOrderResult);

    for (int i = 0; i < n; ++i) {
        cout << postOrderResult[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
