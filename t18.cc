void DeleteDuplication(ListNode **phead)
{ //主要有pnext节点，当前节点，前一个节点，三种节点关系。
    if (phead == nullptr || *phead == nullptr)
    {
        return;
    }

    ListNode *pNode = *phead;    //在内部声明一个pNode,
    LsitNode *preNode = nullptr; //前节点用于

    //如果每个节点不为空的话
    while (pNode != nullptr)
    {
        ListNode *pNext = pNode->next; //下一个节点
        bool needDelete = false;       //是否需要被删除
        //首先判断是否需要被删除，只要下一个节点和当前节点相等
        if (pNext != nullptr && pNext->value == pNode->value)
            needDelete = true; //如果下一个指针不为空且它下一个指针的值和当前指针的值是相等的，则进入可删除模式。
        if (!needDelete)//如果不需要删除的话
        {
            preNode = pNode;//为什么要有prenode呢？因为这里是将最后一个不用删除的
            pNode = pNode->next;

        }
        else{//删除是重点，主要通过
            ListNode * toBeDeleted = pNode;
            int value = pNode->value;//单独拿出一个value,只要和这个Value进行比较，相等就是

            while(toBeDeleted != nullptr && toBeDeleted->value == value)//如果被删除的节点和下一个
            {
                pNext = toBeDeleted->next;
                delete toBeDeleted;
                toBeDeleted = nullptr;
                
                tobedeleted = pNext;
            }
            //如果preNode不为空，则
            if(prenode != nullptr)
            {
                prenode->next = pNext;
                pNode = pNext;
            }
            else
            {
                *phead = pNext;//这是为何？
            }
            
        }
    }
}

//总体编程思路是什么样子的？
/*
函数的参数是什么？ 是头指针而不是头节点，因为如果被删除的节点是头节点的话，那样就无法再用一个头节点的指针表示整个链表了
所以使用了 ListNode** phead，

第一步就是判断 phead和*phead是否为空，如果为空，则直接返回，
所以用 
 if(phead == nullptr || *phead == nullptr) return;

接下来，必然就是初始化，需要有两个链表节点的指针，一个用于遍历，一个用于指向重复节点的前一个节点
ListNode *pNode = *phead;
ListNode *pPreNode = nullptr;
为什么要有这两个节点呢，是因为pPreNode用于指向重复节点之前的那个节点，pNode则是当前节点，
while(pNode!= nullptr){}  为什么是pNode != nullptr? 因为这是表明遍历到最后一个节点。pNode是用于遍历至最后一个节点的。
在遍历到最后一个节点的过程中，发生了对某些节点是否需要删除的判断。
pNode的下一个节点的值是否等于pNode的值， 因此有了 pNext = pNode->next;
而 if(pNext != nullptr && pNext->value == pNode->value)  则说明，需要进行删除了。
这里可以不去写一个具体函数，而是通过一个局部变量来表达是否可以进行删除行为。
bool tobedel = false;
因此 
if(pNext != nullptr && pNext->value == pNode->value)  tobedel = true;

那么下一步，就是再用一个if语句，将 if(tobedel == true)的情况来判断。
如果不用删除，则肯定是继续遍历下去，然而每次都要确立新的preNode，而如果需要删除，则需要把value单独提出来，然后每个节点都和value比较
如果等于value，则删除，且到下一个节点继续比较，这里要判断，被删除的节点是否有一个
删除重复节点的这一部分，

preNode是否为空指针也是要考虑的，因为pPrenode为空，说明，之前


会有一个


*/