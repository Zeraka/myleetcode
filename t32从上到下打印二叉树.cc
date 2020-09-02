/*
先放入头节点，头节点弹出
弹出同时将头节点的左右子树放入 
再将队列的底部弹出，弹出后再加入
第一步是什么？ 新建了一个队列，当然是要往队列里面添加东西了。

1 判断参数为空的情况
2 声明一个队列，
3 将头节点放入队列
4 只要队列不为空， 就一边弹出，一边输入 ，直到整个树都被前序遍历完
5 先提前指向队列前，然后再弹出队列前，如果不这样的话，那第一次的头节点被弹出后队列中就是空的
6 然后再判断左右子节点是否为空，如果不为空就放入队列中去
*/
#include<iostream>

using namespace std;

typedef struct BinaryTreeNode{
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode * right;
}BinaryTreeNode;
/*
void printfromtoptobottom(BinaryTreeNode* pNode){
    if(pNode == nullptr)    return;

    std::deque<BinaryTreeNode> dq;
    //首先必须将pNode插入dq中去，如果不插入的话，就会有很大的问题。
    dq.push_back(pNode);//尾部插入，那当然是头部输出了。还有啥问题吗？
    while(dq.size()){
        BinaryTreeNode* anode = dq.front();//这是队列顶部。
        dq.pop_front();

        printf("%d\n", anode->value);

        if(anode->left) dq.push_back(anode->left);
        if(anode->right) dq.push_back(anode->right);
    }
}
*/
/*
void printfromttob(BinaryTreeNode* pnode){
    if(pnode == nullptr) return;

    std::deque<BinaryTreeNode>  bt;
    bt.push_back(pnode);

    while(bt.size())
    {
        BinaryTreeNode* anode = bt.front();
        bt.pop_front();

        print("%d", anode->value);

        if(anode->left) bt.push_back(anode->left);
        if(anode->right) bt.push_back(anode->right);
    }
}

*/

void func(BinaryTreeNode* pnode){
    if(pnode == nullptr)    return ;

    std::deque<BinaryTreeNode> bt;
    bt.push_back(pnode);

    while(bt.size()){//直到队列中的所有节点都被弹出来，再搞其他的。
        BinaryTreeNode* anode = bt.front();
        bt.pop_front();

        printf("%d", anode->value);

        if(anode->left)  bt.push_back(anode->left);
        if(anode->right) bt.push_back(anode->right);
    }
}
    