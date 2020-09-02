/*
要实现队列的两个函数，appendTail和deletehead。
这里用到了模板
模板可以是类模板，也可以是函数模板
其格式均是在它们之前加上 template<typename T>
首先是将队列的模板类建立好，

*/
template<typename T> class Queue{
    public:
    Queue();
    ~Queue();

    void appendTail(const T& node);
    T deleteHead();

    private:
    stack<T> stack1;
    stack<T> stack2;
};

template<typename T> void Queue<T>::appendTail(const T& node){
    stack1.push(node);//
}

template<typename T> T Queue<T>::deleteHead(){


   if(stack2.size() <= 0){//
       while(stack1.size()){
           T& data = stack1.top();
           stack1.pop();
            stack2.push(data);
       }
   }
   if(stack2.size() == 0)
    throw new exception("queue is empty");//如果一通操作后stack2还是为0，那queue本身就是空的

    T head = stack2.top();
    stack2.pop();

    return head;
}