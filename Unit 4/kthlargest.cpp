#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

int kthLargest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    TreeNode* current = root;
    vector<int> elements;

    while (current || !st.empty()) {
        while (current) {
            st.push(current);
            current = current->right;
        }
        current = st.top();
        st.pop();
        elements.push_back(current->val);
        if (elements.size() == k) {
            return current->val;
        }
        current = current->left;
    }
    return -1;
}

TreeNode* insert(TreeNode* root, int value) {
    if (!root) {
        return new TreeNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

TreeNode* buildBST(vector<int>& nums) {
    TreeNode* root = nullptr;
    for (int num : nums) {
        if (num == -1) {
            break;
        }
        root = insert(root, num);
    }
    return root;
}

int main() {
    vector<int> input_elements;
    int num;
    while (cin >> num) {
        if (num == -1) {
            break;
        }
        input_elements.push_back(num);
    }

    int k;
    cin >> k;

    TreeNode* root = buildBST(input_elements);

    int result = kthLargest(root, k);
    cout << result << endl;

    return 0;
}
