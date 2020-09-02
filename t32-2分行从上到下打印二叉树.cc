/*
为什么需要两个变量？

第一个变量？ 
二叉树的层？
下一层节点的数目是可以通过、、

因为子节点只会在下一层，所以只要该节点有子节点，下一层要打印的节点数目就加1
而如果，没有因为

由于头节点这一层必然只有 1个数， 所以，当前层还剩被打印的数就是1，而下一层待打印的数随着当前层被弹出去后
通过判断子节点是否存在而加1，而当前层的数减为0之后，就说明当前层打印完了，然后将下一层的数赋给当前层即可。
因此，使用
只要当前层有需要打印的内容的

为啥要有队列？ 队列就是要有指针指向头部的，否则还有什么用？
*/
typedef struct btree{
    struct btree * left;
    struct btree * right;
    int value;
    
}btree;

/*
void Print(btree * pnode){
    if(pnode == nullptr) return;

    int next = 0;
    int current = 1;

    std::queue<btree> bt;

    bt.push(pnode);

    while(bt.size()){

        btree* anode = bt.front();

        bt.pop();
        --current;

        print("%d", anode->value);

        if(anode->left){
            next++;
            bt.push(anode->left);
        }
        if(anode->right)
        {
            next++;
            bt.push(anode->right)
        }

        if(current == 0)
        {
            print("\n");
            current = next;
            next = 0;
        }
    }

}*/

void Print(btree* pnode){
    if(pnode == nullptr) return ;

    std::queue<btree> bt;
    bt.push(pnode);

    int next = 0;
    int current = 1;

    while(bt.size()){
        btree* anode = bt.front();

        bt.pop();
        printf("%d",anode->value);
        current--;

        if(anode->left){
            bt.push(anode->left);
            ++next;
        }
        if(anode->right){
            bt.push(anode->right);
            ++next;
        }

        if(current == 0){
            current = next;
            next = 0;
            printf("%n");
        }



    }

}