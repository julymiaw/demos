#include "BinaryTree.h"

bool BinaryTree::right()
{
    if (!root)
        return false;
    right(root);
    return true;
}

TreeNode *BinaryTree::right(TreeNode *node)
{
    if (!node)
        return node;
    if (node->right)
        node->right = right(node->right);
    if (node->left)
    {
        TreeNode *temp = node->right;
        node->right = right(node->left);
        node->left = nullptr;
        TreeNode *t = node->right;
        while (t && t->right)
        {
            t = t->right;
        }
        t->right = temp;
    }
    return node;
}

int main()
{
    BinaryTree x;
    int y[11] = {10, 8, 12, 6, 9, 11, 14, 5, 7, 13, 15};
    for (int i = 0; i < 11; i++)
    {
        x.insert(y[i]);
    }
    x.inorder();
    printf("\n");
    x.right();
    x.inorder();
}