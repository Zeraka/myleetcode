/*
二叉树的深度如何求

就是求最长路径
就是求路径，从头节点到达某个子节点，其路径最长。
那就是遍历呗

可以用递归吗？
二叉树的题，无非是遍历，和求路径两类。 路径这种，用递归非常好解决。
*/
typedef struct btree
{
    struct btree *left;
    struct btree *right;
    int value;
    
};

int maxlength(btree* pnode)
{
    if(pnode->left == nullptr && pnode->right == nullptr){
        return 1;
    }

    int left = 0;
    int right = 0;
    if(pnode->left)
    left = maxlength(pnode->left);
    if(pnode->right)
    right = maxlength(pnode->right);

    //三元运算符, ()?():()
    return (left>right)?(left+1):(right+1);
}