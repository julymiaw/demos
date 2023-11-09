#include <iostream>

template <class T>
void ChangeSize1D(T *&a, const int oldSize, const int newSize)
{
    if (newSize < 0)
    {
        throw std::runtime_error("New size must be >= 0");
    }

    T *newArray = new T[newSize]; // 创建一个新的数组

    int elementsToCopy = (oldSize < newSize) ? oldSize : newSize; // 确定要复制的元素数量

    for (int i = 0; i < elementsToCopy; ++i)
    {
        newArray[i] = a[i]; // 复制元素到新数组
    }

    delete[] a; // 释放旧数组的内存

    a = newArray; // 更新指针指向新数组
}

template <class T>
class Stack
{
public:
    Stack(int stackCapacity = 10);
    int size() { return top + 1; }
    bool IsEmpty() const;
    T &Top() const;
    void Push(const T &item);
    void Pop();

private:
    T *stack;
    int top;
    int capacity;
};

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
    if (capacity < 1)
        throw "stack capacity must be > 0";
    stack = new T[capacity];
    top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const { return top == -1; }

template <class T>
inline T &Stack<T>::Top() const
{
    if (IsEmpty())
        throw "Stack is empty";
    return stack[top];
}

template <class T>
void Stack<T>::Push(const T &x)
{
    if (top == capacity - 1)
    {
        ChangeSize1D(stack, capacity, 2 * capacity);
        capacity *= 2;
    }
    stack[++top] = x;
}

template <class T>
void Stack<T>::Pop()
{
    if (IsEmpty())
        throw "Stack is empty.Cannot delete.";
    stack[top--].~T();
}