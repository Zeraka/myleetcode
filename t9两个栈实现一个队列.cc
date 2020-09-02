/*
如何用两个栈实现一个队列呢？
    要记住的核心的关键，就是向队列中添加是正常的压栈操作
    而是弹出队列就要把stack1中的所有一次压入stack2中，然后再弹出stack2的顶部。
    首先就是要判断stack2是否为空，如果为空，就全部压入stack1,如果不为空那就先从stack2弹


*/
template<typename T> class Queue{
    private:
    stack<T> stack1;
    stack<T> stack2;

    public:
    Queue();
    ~Queue();

    void appendTail(const T& node);
    T deleteHead();
};

template<typenme T> void Queue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template<typename T> T Queue<T>::deleteHead()
{
    if(stack2.size()<=0)
    {
        while(stack1.size())
        {
            T& node =  stack1.top();
            stack1.pop();
            stack2.push(node);
        }
    }
    if(stack2.size()==0)
        throw new exception("queue is empty");

    T& head = stack2.top();
    stack2.pop();

    return head;
}