/*
此题考察深度优先搜索
深度优先遍历算法是怎样的呢？
有两种方式，一是迭代，而是递归

此题难点在于哪里？
    打印路径。

表示所有路径的数据结构是什么？


对于二叉树的深度优先遍历，可以直接理解为先序遍历
前序就是根左右。

关键就在于使用 string path 这一拷贝，值拷贝使得path继续了之前的路径，从而达到stack的效果。

*/

struct TreeNode{
    struct TreeNode* left;
    struct TreeNode* right;
    int val;
    TreeNode(int x):val(x), left(nullptr),right(nullptr){}
};
class Solution{
    public:
    vector<string> vs;//全局的变量，对于递归函数来说，有时候必须要全局变量来做整体的状态
    vector<string> binaryTreePaths(){

        string path;//对于dfs来说，是整个dfs函数的作用域
        dfs(root,path)//一开始的path是空的
        return vs;
    }

    void dfs(TreeNode *root, string path)
    {
        if(root == nullptr) return;

        path += to_string(root->val);//第一次就会有
        if(root->left == nullptr && root->right ==nullptr)
            vs.push_back(path);
        else
        {
            path += "->";
        }
        dfs(root->left,path);//继续之前走过的路径
        dfs(root->right,path);
        
    }

};