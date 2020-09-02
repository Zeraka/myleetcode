/*
该题思路是什么呢？
两链表合并，且两个链表本身就是有序的，因此，两个链表的
两个链表互相比较，分别有两个指针从它们的头节点开始，每次都是两个指针指向的节点进行比较
谁小谁就作为新链表的节点并尾插入，然后再移动到下一个节点上，
重复比较
每次比较都是两个链表，于是可以用递归的思路解决。

小的那一方就是新的链表的节点，该节点的下一个就是用同样的方法得到的节点，
所以最后的出口，肯定是有一个链表指向了空，而另一个没有，所以没有指向空的所有部分就可以作为新链表最后的部分了


*/
typedef struct ListNode{
    int value;
    struct ListNode *next;
}ListNode;

/*
ListNode* Merge(ListNode* pa, ListNode* pb)
{   
    //出口条件怎么写？
    //如果pa为空，则直接返回pb,因为pb就是不用再去排了
    if(pa == nullptr) return pb;
    else if(pb == nullptr) return pa;
    

    ListNode* newp = nullptr;

    if(pa->value > pb->value)
    {
        newp = pb;
        newp->next = Merge(pa, pb->next);
    }else{
        newp = pa;
        newp->next = Merge(pa->next, pb);
    }
}

*/ 

ListNode* Merge(ListNode*pa, ListNode*pb)
{
    if(pa == nullptr) return pb;
    else if(pb == nullptr) return pa;

    ListNode * np = nullptr;

    if(pa->value < pb->value)
    {
        np = pa;
        np->next = Merge(pa->next,pb);
    }
    else{
        np = pb;
        np->next = Merge(pa,pb->next);
    }

    return np;
}// 3min,还行，但是这只是趁热打铁。 