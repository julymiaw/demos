#include <iostream>

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
    BinaryTree(TreeNode *node = nullptr) : root(node) {}

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

    void preorder()
    {
        preorder(root);
    }

    int depth();

    bool right();

    void reverse();

private:
    void inorder(TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        inorder(node->left);
        std::cout << node->val << " ";
        inorder(node->right);
    }

    void preorder(TreeNode *node)
    {
        if (!node)
        {
            return;
        }
        std::cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    int depth(TreeNode *node);

    void reverse(TreeNode *node);

    TreeNode *right(TreeNode *node);

    TreeNode *root;
};
