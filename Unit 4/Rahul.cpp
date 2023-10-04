#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void convertToMirror(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    swap(root->left, root->right);

    convertToMirror(root->left);
    convertToMirror(root->right);
}

int main()
{
    int N;
    cin >> N;
    TreeNode *root = nullptr;

    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        if (root == nullptr)
        {
            root = new TreeNode(val);
        }
        else
        {
            TreeNode *current = root;
            while (true)
            {
                if (val < current->data)
                {
                    if (current->left == nullptr)
                    {
                        current->left = new TreeNode(val);
                        break;
                    }
                    current = current->left;
                }
                else
                {
                    if (current->right == nullptr)
                    {
                        current->right = new TreeNode(val);
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    cout << "Original tree: ";
    preorder(root);
    cout << endl;

    convertToMirror(root);

    cout << "Mirror Image: ";
    preorder(root);
    cout << endl;

    return 0;
}
