#include "Stack.h"

template <class T>
class QueueUsingStacks
{
public:
    // 构造函数
    QueueUsingStacks()
    {
        // 初始化两个栈
        inputStack = Stack<T>();
        outputStack = Stack<T>();
    }

    // 将元素推入队列
    void push(const T &value)
    {
        inputStack.Push(value);
    }

    // 从队列中弹出元素
    T pop()
    {
        if (outputStack.IsEmpty())
        {
            // 如果输出栈为空，将输入栈的元素逐个出栈并推入输出栈
            while (!inputStack.IsEmpty())
            {
                outputStack.Push(inputStack.Top());
                inputStack.Pop();
            }
        }
        if (outputStack.IsEmpty())
        {
            // 如果输出栈仍然为空，表示队列为空
            throw "Queue is empty";
        }
        T front = outputStack.Top();
        outputStack.Pop();
        return front;
    }

    // 查看队列的头部元素
    T peek()
    {
        if (outputStack.IsEmpty())
        {
            // 如果输出栈为空，将输入栈的元素逐个出栈并推入输出栈
            while (!inputStack.IsEmpty())
            {
                outputStack.Push(inputStack.Top());
                inputStack.Pop();
            }
        }
        if (outputStack.IsEmpty())
        {
            // 如果输出栈仍然为空，表示队列为空
            throw "Queue is empty";
        }
        return outputStack.Top();
    }

    // 检查队列是否为空
    bool empty()
    {
        return inputStack.IsEmpty() && outputStack.IsEmpty();
    }

private:
    Stack<T> inputStack;  // 输入栈
    Stack<T> outputStack; // 输出栈
};
