#include "Chain.h"
#include <iostream>

template <class T>
void Chain<T>::reverseList()
{
    ChainNode<T> *prev = nullptr;
    ChainNode<T> *current = first;
    ChainNode<T> *next = nullptr;

    last = first;

    while (current != nullptr)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }

    first = prev;
}

int main()
{
    Chain<int> chain;
    for (int i = 1; i <= 6; ++i)
    {
        chain.insertBack(i);
    }

    std::cout << "反转前的链表：";
    for (auto it = chain.begin(); it != chain.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    chain.reverseList();

    std::cout << "反转后的链表：";
    for (auto it = chain.begin(); it != chain.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
