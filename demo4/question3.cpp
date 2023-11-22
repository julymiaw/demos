#include "Chain.h"
#include <iostream>

template <class T>
ChainNode<T> *getIntersectionNode(const Chain<T> *A, const Chain<T> *B)
{
    ChainNode<T> *x = A->first;
    ChainNode<T> *y = B->first;
    ChainNode<T> *t = nullptr;
    bool status = false;

    while (x != B->last && y != A->last)
    {
        x = x->getLink();
        y = y->getLink();
        if (x == nullptr)
            x = B->first;
        if (y == nullptr)
            y = A->first;
        if (x->getData() == y->getData())
        {
            if (!status)
                t = x;
            status = true;
        }
        if (status && x->getData() != y->getData())
            status = false;
    }
    return status ? t : nullptr;
}

// 测试用例1: 两个链表没有交点
void Check1()
{
    // 创建两个链表
    Chain<int> chainA;
    Chain<int> chainB;

    // 向两个链表中添加节点
    for (int i = 1; i <= 3; ++i)
    {
        chainA.insertBack(i);
    }
    for (int i = 1; i <= 5; ++i)
    {
        chainB.insertBack(i);
    }

    // 创建交点
    for (int i = 10; i <= 15; ++i)
    {
        chainA.insertBack(i);
        chainB.insertBack(i);
    }

    // 打印两个链表
    std::cout << "链表A：";
    for (auto it = chainA.begin(); it != chainA.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "链表B：";
    for (auto it = chainB.begin(); it != chainB.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 找到并打印交点
    ChainNode<int> *intersection = getIntersectionNode(&chainA, &chainB);
    if (intersection != nullptr)
    {
        std::cout << "交点的值是：" << intersection->getData() << std::endl;
    }
    else
    {
        std::cout << "两个链表没有交点" << std::endl;
    }
}

// 测试用例2: 两个链表有一个公共节点
void Check2()
{
    // 创建两个链表
    Chain<int> chainA;
    Chain<int> chainB;

    // 向两个链表中添加节点
    for (int i = 1; i <= 3; ++i)
    {
        chainA.insertBack(i);
    }
    for (int i = 1; i <= 5; ++i)
    {
        chainB.insertBack(i);
    }

    // 创建交点
    chainA.insertBack(10);
    chainB.insertBack(10);

    // 打印两个链表
    std::cout << "链表A：";
    for (auto it = chainA.begin(); it != chainA.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "链表B：";
    for (auto it = chainB.begin(); it != chainB.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 找到并打印交点
    ChainNode<int> *intersection = getIntersectionNode(&chainA, &chainB);
    if (intersection != nullptr)
    {
        std::cout << "交点的值是：" << intersection->getData() << std::endl;
    }
    else
    {
        std::cout << "两个链表没有交点" << std::endl;
    }
}

// 测试用例3: 两个链表有多个公共节点
void Check3()
{
    // 创建两个链表
    Chain<int> chainA;
    Chain<int> chainB;

    // 向两个链表中添加节点
    for (int i = 1; i <= 3; ++i)
    {
        chainA.insertBack(i);
    }
    for (int i = 1; i <= 5; ++i)
    {
        chainB.insertBack(i);
    }

    // 创建交点
    for (int i = 10; i <= 15; ++i)
    {
        chainA.insertBack(i);
        chainB.insertBack(i);
    }

    // 打印两个链表
    std::cout << "链表A：";
    for (auto it = chainA.begin(); it != chainA.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "链表B：";
    for (auto it = chainB.begin(); it != chainB.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 找到并打印交点
    ChainNode<int> *intersection = getIntersectionNode(&chainA, &chainB);
    if (intersection != nullptr)
    {
        std::cout << "交点的值是：" << intersection->getData() << std::endl;
    }
    else
    {
        std::cout << "两个链表没有交点" << std::endl;
    }
}
int main()
{
    Check1();
    Check2();
    Check3();
    return 0;
}