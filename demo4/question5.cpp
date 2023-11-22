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

template <class T>
ChainNode<T> *Chain<T>::detectCycle()
{
    ChainNode<T> *slow = this->first;
    ChainNode<T> *fast = this->first;

    while (fast != nullptr && fast->link != nullptr)
    {
        slow = slow->link;
        fast = fast->link->link;

        if (slow == fast)
        { // 存在环
            slow = this->first;
            while (slow != fast)
            {
                slow = slow->link;
                fast = fast->link;
            }
            return slow; // 返回环的开始节点
        }
    }

    return nullptr; // 不存在环
}

template <class T>
void Chain<T>::printList()
{
    ChainNode<T> *cycleStart = this->detectCycle();

    if (cycleStart == nullptr)
    { // 链表无环
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            std::cout << *it << " ";
        }
    }
    else
    { // 链表有环
        ChainNode<T> *current = this->first;
        while (current != cycleStart)
        {
            std::cout << current->data << " ";
            current = current->link;
        }

        std::cout << "["; // 标记环的开始
        do
        {
            std::cout << current->data << " ";
            current = current->link;
        } while (current != cycleStart);
        std::cout << "\b]"; // 标记环的结束
    }

    std::cout << std::endl;
}

int main()
{
    Chain<int> chain;
    // 创建环
    ChainNode<int> *cycleNode = new ChainNode<int>(6);
    chain.insertNode(cycleNode); // 创建环
    for (int i = 11; i >= 7; --i)
    {
        ChainNode<int> *Node = new ChainNode<int>(i);
        chain.insertNode(Node); // 创建环
    }
    chain.insertNode(cycleNode); // 创建环
    for (int i = 5; i >= 1; --i)
    {
        ChainNode<int> *Node = new ChainNode<int>(i);
        chain.insertNode(Node); // 创建环
    }

    if (chain.hasCycle())
        std::cout << "链表开始入环的第一个节点数据为" << chain.detectCycle()->getData() << std::endl;
    chain.printList();

    return 0;
}