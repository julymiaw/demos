#include "BinaryTree.h"

TreeNode *func(int *x, int *y, int length)
{
    int i = 0;
    if (length < 1 || length == 1 && *x != *y)
        return nullptr;

    TreeNode *root = new TreeNode(y[0]);
    // std::cout << "当前的根节点是" << root->val << std::endl;
    while (i < length && x[i] != y[0])
        i++;
    if (i >= length)
        return nullptr;
    int *a = new int[i];
    int *b = new int[i];
    int *c = new int[length - i - 1];
    int *d = new int[length - i - 1];
    for (int j = 0; j < i; j++)
    {
        a[j] = x[j];
        b[j] = y[j + 1];
    }
    root->left = func(a, b, i);
    // if (root->left)
    //     std::cout << "当前的根节点的左节点是" << root->left->val << std::endl;
    for (int j = 0; j < length - i - 1; j++)
    {
        c[j] = x[j + i + 1];
        d[j] = y[j + i + 1];
    }
    root->right = func(c, d, length - i - 1);
    // if (root->right)
    //     std::cout << "当前的根节点的右节点是" << root->right->val << std::endl;
    return root;
}

int main()
{
    int x[11] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; // 中序
    int y[11] = {10, 8, 6, 5, 7, 9, 12, 11, 14, 13, 15}; // 前序
    TreeNode *node = func(x, y, 11);
    BinaryTree z(node);
    z.inorder();
    printf("\n");
    z.preorder();
}