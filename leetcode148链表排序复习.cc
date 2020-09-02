/*
再研究subsort会得到什么问题呢？
分治，把大问题分治为一个个小问题

链表的快速排序再研究？

排序的本质，就是使得 序列的每一个数的左边都小于它，右边都大于它
所以只要能够使得所有数都经历过这种比较，自然就可以排序
快速排序便是如此。
*/

struct ListNode{
    int val;
    struct ListNode* next;
};
class Solution{
    ListNode* quickSort(ListNode* head){
        if(head==nullptr || head->next == nullptr)  return head;

        ListNode* cur = head;

        while(cur->next)
        {
            cur =cur->next;
        }

        subsort(head,cur);
        return head;
    }

    void subsort(ListNode* left, ListNode * right)
    {
        int pivot = left->val;

        ListNode* i = left->next;
        ListNode* j = left->next;
        ListNode* i_pre = left;//必须是left,必须是在一开始在i的前面。
        while(j != right->next){
            if(j->val > pivot)
            {
                j =j->next;
            }else
            {
                i_pre = i;
                swap(i,j);//核心在于交换j和基准的值
                i = i->next;
                j = j->next;
            }
            
        }
        //考虑最坏的情况，那就是基准一开始，右侧的就始终比基准要打
        //所以就没有i_pre， i一直指向了基准的下一个
        swap(left,i_pre);
        subsort(left,i_pre);//这一步已经排序完成了。
        subsort(i,right);

    }

    void swap(ListNode* left, ListNode*right)
    {
        if(left->val == right->val) return;
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
    }
};