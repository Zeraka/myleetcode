/*
如何对链表进行排序？

单向链表的快速排序。
    首先是要有能够交换节点的函数
    
    链表的快速排序，并不是说要将链表重新连接为有序的，而是将链表的值进行交换。
    


对单链表进行快速排序的本质是什么？
快速排序的本质是什么？ i和j一起前进，通过一种比较大意了的方式来完成。
    快速排序算法的本质是什么呢？
    给一个单项链表，如何实现它呢？
    一个基准，两个指针。一个pre
    基准左侧的开区间一定是小于该基准的
    而基准右侧的闭区间一定是大于等于该基准的
    j每次一定会++，碰到
    基准的目的是什么？
    指针的目的又是什么？

    两个指针均从pivot基准右侧开始，pivot基准一般是左边第一个
    两个指针都在左边。

    移动两个指针的目的是，让i左边的数都小于pivot,让
    [i,j]区域包括i,j位置的数

伪代码：

    pivot = arr[0]
    i,j=1
    while(arr[j])
    if arr[j] > pivot:
        j++ #无论如何都是j++,保证[i,j]都是大于pivot的
    else:
        swap(arr[i],arr[j])
        j++
        i++
    
    func(pivot)

    return head;

*/
struct ListNode
{
    int val;
    struct ListNode *next;
};
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        //找到最后一个节点的位置
        ListNode *cur = head;
        while (cur->next)
        {
            cur = cur->next;
        }
        quicksort(head, cur);
    }

    void quicksort(ListNode *left, ListNode *right)
    {
        //本质是分治法
        //判断是否为空
        if (left == nullptr || right == nullptr || left == right)
            return;

        //设置一个基准
        int pivot = left->val;

        ListNode *i = left->next;
        ListNode *j = left->next;
        ListNode *i_pre;

        while (j != right->next)
        {
            if (j->val > pivot)
            {
                j++;
            }
            else
            { //只要j小于基准，就交换i,j节点的值，为什么？
                swap(i, j);
                i_pre = i;
                i = i->next;
                j = j->next;
            }
        }
        //当j走到right的时候，将i前面的一个节点和基准进行交换，保证左侧均比右侧要小
        swap(i_pre,i);
        quicksort(left, i_pre);//
        //printList();
        quicksort(i,right);
    }

    void swap(ListNode *left, ListNode *right)
    {
        int tmp;
        tmp = left->val;
        left->val = right->val;
        right->val = tmp;
    }
};