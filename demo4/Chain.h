template <class T>
class Chain;

// ChainNode定义
template <class T>
class ChainNode
{
    friend class Chain<T>;

public:
    ChainNode(T element, ChainNode *next = 0)
    {
        data = element;
        link = next;
    }
    T getData() { return data; }
    ChainNode *getLink() { return link; }

private:
    T data;
    ChainNode *link;
};

template <class T>
class Chain
{
    template <class U>
    friend ChainNode<U> *getIntersectionNode(const Chain<U> *A, const Chain<U> *B);

public:
    Chain() { first = 0; }
    void insertNode(ChainNode<T> *x);
    void insertBack(const T &e);

    class ChainIterator
    {
    public:
        ChainIterator(ChainNode<T> *startNode = 0) { current = startNode; }

        T &operator*() const { return current->data; }
        T *operator->() const { return &current->data; }

        // 前置递增
        ChainIterator &operator++()
        {
            current = current->link;
            return *this;
        }
        // 后置递增
        ChainIterator operator++(int)
        {
            ChainIterator old = *this;
            current = current->link;
            return old;
        }
        // 判断相等
        bool operator!=(const ChainIterator right) const
        {
            return current != right.current;
        }
        bool operator==(const ChainIterator right) const
        {
            return current == right.current;
        }

    private:
        ChainNode<T> *current;
    };
    ChainIterator begin() { return ChainIterator(first); }
    ChainIterator end() { return ChainIterator(0); }

    ChainNode<T> *findKthFromEnd(int k);
    void reverseList();
    bool hasCycle();
    ChainNode<T> *detectCycle();
    void printList();

private:
    ChainNode<T> *first;
    ChainNode<T> *last;
};

// 插入节点到链表头部
template <class T>
void Chain<T>::insertNode(ChainNode<T> *x)
{
    if (first == nullptr)
    {
        first = x;
    }
    else
    {
        x->link = first;
        first = x;
    }
}

// 添加数据到链表尾部
template <class T>
void Chain<T>::insertBack(const T &e)
{
    if (first == nullptr)
    {
        first = last = new ChainNode<T>(e);
    }
    else
    {
        last->link = new ChainNode<T>(e);
        last = last->link;
    }
}