#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    BinaryTree() : root(nullptr) {}

    void insert(int val)
    {
        if (!root)
        {
            root = new TreeNode(val);
            return;
        }
        TreeNode *cur = root;
        while (cur)
        {
            if (val < cur->val)
            {
                if (!cur->left)
                {
                    cur->left = new TreeNode(val);
                    return;
                }
                cur = cur->left;
            }
            else
            {
                if (!cur->right)
                {
                    cur->right = new TreeNode(val);
                    return;
                }
                cur = cur->right;
            }
        }
    }

    void inorder()
    {
        inorder(root);
    }

private:
    void inorder(TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    TreeNode *root;
};
