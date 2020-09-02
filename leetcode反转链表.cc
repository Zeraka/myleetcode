/*
使用迭代法
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
/*
为什么head->next要设置为nullptr呢？
因为递归是从最后的状态产生的。同时要防止链表循环。
递归实际上也是将大问题化解为小问题，本题中的递归
https://leetcode-cn.com/problems/reverse-linked-list/solution/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/
每层递归函数都返回ret,也就是最后一个节点。
递归的本质是什么呢？
    递归的本质就是利用相对性。
    比如这一题可以先把问题化简为两个节点。
    head 和head->next
    这两个节点要是进行反转，要怎么办呢？ head->next->next = head;
    head->next = nullptr。 这一步是从后往前完成的，不会出现链表断裂的情况。
    最先执行该函数的是，最末尾的节点。

    递归函数就是要考虑的是，最末尾的节点要先执行。

    实际上就是这两步。 只要从尾节点开始，逐次地进行这两步的操作，就能够将整个链表彻底翻转过来。

    怎么办？ 用递归的方式进行反转链表。
    比如，

# 你有什么深刻的理解？
    迭代必然可递归。递归必然可迭代。
    递归是加入了栈的迭代。

    递归的要点就是，一旦进入递归流程，就直接考虑最后的状态的执行。

*/
class Solution
{
    ListNode *reverseList(ListNode *head)
    {
        //跳出条件是什么?如果是单节点的话，就返回该节点
        //确实是会出现当前节点为空的情况。
        //该函数最先执行的相对节点是哪两个？假如head不为空，而head->next为空，
        //那样不会导致为空吗？不会，因为跳出条件已经有了head->next为空的时候的情况，直接返回
        //那这个head为空又代表的是啥呢？这个就是代表原来的链表为空的情况啊，没有什么特别的呀。
        //递归函数特点就是，进入递归后，其域内的下一步都是递归执行完再完成的。
        //所以，在reverList()函数执行完之前，下面的head->next->next = head;和head->next = nullptr;是不执行的
        //这才是关键。这样就说的通了。
        //递归的本质是可以重复做一件事且利用以前做过的成果。

         
        if (head == nullptr || head->next == nullptr)//为什么会有这一步呢？
            return head;

        ListNode *ret = reverseList(head->next);//假设已经把head->next后面的全部完成了。而只剩下了head还没有连接了
        head->next->next = head;//当前节点
        head->next = nullptr; //防止链表循环，所以设置为空。
        
        
        


        return ret;
        //
    }
};

class Solution2{
    ListNode* reverseList(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* cur = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return cur;//最后一次cur得到的是尾节点，并且将尾节点作为了新的头节点。
    }
};
