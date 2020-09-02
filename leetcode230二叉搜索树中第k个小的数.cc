/*
如果是求二叉搜索树中最小的数，则需要通过

就是通过中序遍历，可以得到二叉搜索树的顺序序列
每得到(打印)一个数之前k--,
只要左子树为空，就打印，因此k--
--k;
if(k == 0) printf("%d", node->value);

这题要注意的是异常情况的判断

leetcode的官方方法，可以说是一定会有
本题的优化是如何进行裁剪，使得不需要将所有的路径扫描完，而是在找到第K个后将其返回

C++向vector中添加元素，即 push_back()方法。

*/
/*
class Solution{
    public:
    int kthSmallest(TreeNode* root, int k){
        if(root == nullptr) return -1;

        if(root->left) kthSmallest(root->left, k);
        else k--;
        if(k == 0) return root->val;

        if(root->right) kthSmallest(root->right, k);
    }

    
};
Line 22: Char 5: fatal error: control may reach end of non-void function [-Wreturn-type]
    }}
    报这样的错是因为返回值类型错误，因为该函数必然返回一个int,但是该函数有出现无法返回的可能


*/
class Solution{
    public:
    vector<int> res;
    int kthSmallest(TreeNode* root, int k){
        if(root == nullptr) return -1;

        dfs(root, k);
    }

    void dfs(TreeNode* root, int k){
        if(root == nullptr) return;
        if(root->left){
            dfs(root->left, k);
        }

        //对中序进行一次操作
        res.push_back(root->val);


        if(root->right) dfs(root->right, k)
    }
};