#include "BinaryTree.h"

void BinaryTree::reverse()
{
    reverse(root);
}

void BinaryTree::reverse(TreeNode *node)
{
    if (!node)
        return;
    TreeNode *temp = node->left;
    node->left = node->right;
    node->right = temp;
    reverse(node->right);
    reverse(node->left);
}

int main()
{
    BinaryTree x;
    int y[11] = {10, 8, 12, 6, 9, 11, 14, 5, 7, 13, 15};
    for (int i = 0; i < 11; i++)
    {
        x.insert(y[i]);
    }
    x.preorder();
    printf("\n");
    x.reverse();
    x.preorder();
}