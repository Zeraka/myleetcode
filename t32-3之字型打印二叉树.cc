/*
之字形打印二叉树，
其实就是在分层的基础上，再加一个栈，
加一个行数i初始为1， 要current为0， 就++i,
如果i为奇数，就直接打印，而i为偶数的话，弹出后进入另一个栈中，等current为0的时候，再弹出打印，然后\n
实践证明，我的比剑指offer的方法还要好，

*/

typedef struct btree{
    btree* left;
    btree* right;
    int value;
}btree;

void Print(btree* pnode){
    if(pnode == nullptr)  return;

    std::queue<btree> bt;
    std::queue<btree> ct;

    int current = 1;
    int next = 0;
    int level = 1;

    bt.push(pnode);

    while(bt.size()){
        
        btree* anode = bt.front();

        bt.pop();
        --current;
        if(level & 1 == 1){
           printf("%d", anode->value);
        }else{
            ct.push(anode);
        }

        if(anode->left){
            ++next;
            bt.push(anode->left);
        }
        if(anode->right)
        {
            ++next;
            bt.push(anode->right);
        }

        if(current == 0){
            level++;
            current = next;
            next = 0;

            Print("\n");

            while(ct.size()){
                btree* bnode = ct.front();
                ct.pop();
                print("%d",bnode);
            }
            print("\n");
        }
    }
}