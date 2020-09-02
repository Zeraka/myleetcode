/*
如何确定链表中包含环呢？ 总体思路是：
只要使用快慢指针，快指针一定会和慢指针相交，或者说追上了慢指针。
而如何判断环的入口呢？
快指针移动n步后，慢指针移动一步，此后，快慢指针保持相同的速度即可。
而要得到这个n，n即为环中节点数。应该怎么办呢？

既然是快慢指针，则两指针相遇一定是在环中，只要第一次相遇，自此做一个flag,然后慢指针再一次回到该节点
途中经过的步数，就是环中节点数，有了环中节点数，快指针就可以移动N步，然后和慢指针第一次相交的节点，即为
环的入口。

具体编程思路是：


设置快慢指针 listnode * slow, *fast;
Listnode* slow = phead
设计一个函数找到快慢指针相遇的节点. 这里要注意什么问题？ 要注意判断是否有环
如果无环，则会有
该函数，只要返回nullptr，则代表无环，否则返回有环，这个是首先规定好的
怎么记住这个源代码？ 
    首先是要判断fast指针是否是空的，因为快指针一定会有一个

将redis彻底背下来，也算是一种功力了，总之，一定要干好。


*/

struct listnode
{   
    listnode* next;
    int value;/* data */
};

listnode* MeetingNode(listnode* phead){
     if(phead == nullptr)
     return nullptr;

     listnode* slow = phead;
     listnode* fast = phead;
    
    if(fast->next == nullptr)
        return nullptr;
    else
    {
        fast = fast->next;
    }//一开始快指针比慢指针快一步，然后判断是否为空，为空就直接返回，单节点肯定无环。
    
     while(fast != nullptr && slow != nullptr)//为什么两个都要判断？这里是不需要判断尾节点，所以直接就用node
     {
         if (fast == slow) return slow;
         slow = slow->next;
         fast = fast->next;
         if(fast != nullptr)
            fast = fast->next;

        
     }

     return nullptr;//只要跳出这个循环，就一定无环，只要返回了Nullptr，就一定无环。
}

/*

*/
