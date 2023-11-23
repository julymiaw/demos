#include "BinaryTree.h"
#include <iostream>

int BinaryTree::depth()
{
    return depth(root);
}

int BinaryTree::depth(TreeNode *node)
{
    if (!node)
        return 0;
    return std::max(depth(node->left), depth(node->right)) + 1;
}

int main()
{
    BinaryTree x;
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            x.insert(4 - i);
        else
            x.insert(i);
    }
    x.inorder();
    printf("\nx的深度是:%d", x.depth());
}
