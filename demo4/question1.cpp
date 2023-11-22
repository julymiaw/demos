#include "Chain.h"
#include <iostream>

// 寻找倒数第k个节点
template <class T>
ChainNode<T> *Chain<T>::findKthFromEnd(int k)
{
    ChainNode<T> *first = this->first;
    ChainNode<T> *second = this->first;

    for (int i = 0; i < k; ++i)
    {
        if (first == nullptr)
        {
            return nullptr; // 如果k大于链表长度，返回null
        }
        first = first->link;
    }

    while (first != nullptr)
    {
        first = first->link;
        second = second->link;
    }

    return second; // 返回倒数第k个节点
}

int main()
{
    Chain<int> chain;
    for (int i = 1; i <= 6; ++i)
    {
        chain.insertBack(i);
    }

    ChainNode<int> *node = chain.findKthFromEnd(3);

    std::cout << "倒数第3个节点的值是：" << node->getData() << std::endl;

    return 0;
}