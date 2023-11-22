#include "Chain.h"
#include <iostream>

template <class T>
bool Chain<T>::hasCycle()
{
    ChainNode<T> *slow = this->first;
    ChainNode<T> *fast = this->first;

    while (fast != nullptr && fast->link != nullptr)
    {
        slow = slow->link;
        fast = fast->link->link;

        if (slow == fast)
        {
            return true; // 存在环
        }
    }

    return false; // 不存在环
}

void Check1()
{
    Chain<int> chain;
    for (int i = 1; i <= 5; ++i)
    {
        chain.insertBack(i);
    }
    if (chain.hasCycle())
        std::cout << "存在环，无法打印\n";
    else
    {
        std::cout << "链表1：";
        for (auto it = chain.begin(); it != chain.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}
void Check2()
{
    Chain<int> chain;
    // 创建环
    ChainNode<int> *cycleNode = new ChainNode<int>(6);
    chain.insertNode(cycleNode); // 创建环
    for (int i = 1; i <= 5; ++i)
    {
        ChainNode<int> *Node = new ChainNode<int>(i);
        chain.insertNode(Node); // 创建环
    }
    chain.insertNode(cycleNode); // 创建环

    if (chain.hasCycle())
        std::cout << "链表2存在环\n";
    else
    {
        std::cout << "链表2：";
        for (auto it = chain.begin(); it != chain.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    Check1();
    Check2();
    return 0;
}