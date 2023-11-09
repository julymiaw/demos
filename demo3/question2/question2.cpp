#include <iostream>
#include "QueueUsingStacks.h"

int main()
{
    QueueUsingStacks<int> myQueue;

    // Push elements into the queue
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Peek at the front element
    std::cout << "Front element: " << myQueue.peek() << std::endl;

    // Pop the front element
    std::cout << "Pop element: " << myQueue.pop() << std::endl;

    // Push more elements
    myQueue.push(4);
    myQueue.push(5);

    // Pop and print elements from the queue
    std::cout << "Queue elements: ";
    while (!myQueue.empty())
    {
        std::cout << myQueue.pop() << " ";
    }
    std::cout << std::endl;

    if (myQueue.empty())
    {
        std::cout << "Queue is empty." << std::endl;
    }
    else
    {
        std::cout << "Queue is not empty." << std::endl;
    }

    return 0;
}
