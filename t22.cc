/*
链表中第K个节点的思路是如何的呢？
双指针，preNode和Node,当Node移动K-1次之后，将preNode赋值为头节点，之后preNode就和Node一起移动


于是在Node移动到末尾之后
preNode和Node一起移动到最后所指的那个点，就是链表中的倒数第K个节点。

但是这一题主要考察的就是鲁棒性，
有三种情况，K大于链表长度
输入的是空指针
K为0

为什么？ K大于链表长度的话， for循环中 i < k - 1 就会使得pNode超出原链表长度，因此还是会造成错误
输入的是空指针，这个是所有该类题目的通用的注意事项
如果输入的K为0，则K-1也会导致错误

所以 if(phead == nullptr || k <= 0 ) return nullptr; 这个部分，是为了防止输入空链表以及K被恶意的输入小于等于0的数，
如果K小于等于0，显而易见这肯定会导致输入出错。

如何记住？
    设计链表的题目，鲁棒性是很必要的，比如 头节点是否为空——链表是否为空
    而倒数第K个，这个K就隐含了K不能为负，且K也不能超过链表长度，且K也不能为0，因为没有倒数第0个。

而如果K大于链表会如何？ 
for (unsigned int i = 0; i < k - 1 ; i++){} 这用于将pNode移动k-1次，而如果K大于链表长度的话，该循环就会出现溢出。
但是又不能通过遍历链表的方式来获取链表长度，因为这会导致产生一个O(n)的时间复杂度。
那要怎么办呢？ 
    如果k大于了链表，那么在做循环的时候，一定会超过，此时pNode一定为nullptr,所以，只要判断其是否为
    nullptr则可以判断其是否超过了链表长度。 

for(unsigned int i; i < k -1 ; ++i)
{
    if(pNode->next != nullptr)
    {
        pNode = pNode->next;
    }
    else{
        return nullptr; //返回nullptr则代表输入出了错误。
    }
}
这里用pNode->next是因为一旦有pNode->next为空则代表pNode必然为尾节点。

怎么记？
    时刻判断尾节点
    pNode->next为空，代表pNode是尾节点，该语句常用到

# 快慢指针还可以用于各种功能的

*/

struct listnode{
    int value;
    listnode* next;
};

listnode* findKthtofail(listnode* phead,unsigned int k){
    if(phead == nullptr || k <= 0)
    return nullptr;

    listnode * pNode = phead;//这个是地址
    listnode * prenode = phead;

    for (unsigned int i = 0; i < k - 1; ++i)
    {
        if(pNode->next != nullptr)
        {
            pNode = pNode->next;
        }else{
            return nullptr;
        }
    }

    while(pNode->next)//只要pNode不是尾节点
    {
        pNode = pNode->next;
        prenode = prenode->next;
    }

    return prenode;
    
}