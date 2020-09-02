/*
此题必须背得滚瓜烂熟
本题考查三目运算符，大数相加原理以及虚拟头节点(哨兵)的使用
关于哨兵的使用，可以复习LRU算法。


递归方法如何使用呢？
三目运算符是如何使用的呢？

*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
    //不用循环，而是直接递归也可以。
    //递归
};




/*
class Solution
{
    ListNode *addtwoNumbers(ListNode *l1, ListNode *l2)
    {
        if(l1 == nullptr || l2 == nullptr)  return nullptr;

        int c = 0;
         ListNode* head =new ListNode(0);
        ListNode* cur = head, *del = head;

        while(l1||l2||c)
        {
            l1 = l1!=nullptr?(c+=l1->val,l1=l1->next):l1;
            l2 = l2!=nullptr?(c+=l2->val,l2=l2->next):l2;
            cur->next = new ListNode(0);
            cur = cur->next;
            cur->val = c%=10;
            c/=10;
        }

        cur->next = nullptr;//其实不用写，因为初始化后必然是nullptr
        head = head->next;
        delete del;
        return head;



    }
};
*/
/*
研究此代码,看其效果如何吧。
设置一个哨兵有什么好处呢》？


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int c=0;

    //产生一个哨兵头节点。 
    struct ListNode *head=(struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur=head,*del=head;//分配了哨兵之后，又将cur和del指向了head。
    //head虚拟头结点地址,cur当前节点地址,del用于删除虚拟头结点
    while(l1!=NULL||l2!=NULL||c)
    {
        cur->next=(struct ListNode *)malloc(sizeof(struct ListNode));//分配一个节点
        cur=cur->next;//
        l1=l1!=NULL?(c+=l1->val,l1->next):l1;//如果l1不为空，则c加上l1的值，l1指向下一个。否则l1就不变了。
        l2=l2!=NULL?(c+=l2->val,l2->next):l2;//如果l2不为空，则c加上l2的值，l2指向下一个，否则l2就不变。
        cur->val=c%10;//当前的值就是和10同余得到的，需要进位的数就是除以10得到的。
        c=c/10;//由于是一位一位进位的，所以这里会有
    }
    cur->next=NULL;//cur最后肯定是尾节点了
    head=head->next;//删除头节点的第一步，是
    free(del);
    return head;

作者：baal-3
链接：https://leetcode-cn.com/problems/add-two-numbers/solution/zui-jian-xie-fa-by-baal-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

/*
总体思路是什么呢？
  首先是建立头节点，需要为头节点申请内存空间，
  del,cur指针都指向head节点
    声明一个c，如果是
  当l1，l2和c只要有一个不为空，则循环执行以下内容：
    分配一个节点的内存 (struct ListNode*)malloc(sizeof(struct ListNode)),给cur->next(cur一开始是指向head节点的)
    l1如果不为空，就 把l1当前节点的值放入C中，并且将l1=l1->next,如果为空就不做任何操作
    这里不使用双指针，而是用一个int 类型的变量，存储两个链表节点所得的值。
    每次得到的值的小于10的部分会被放入cur->val。
    而其十位数会留着作为下一次循环的加数。
    这样就解决了进位的问题。

    当循环跳出以后，将head = head->next,而后free(del),释放掉哨兵节点。
    再返回head.

    释放内存的小技巧就是，用一个专门的指针指向要释放的节点，最后用该指针作为参数去释放它。
*/

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *addtwonumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr || l2 == nullptr)
        return nullptr;

    int c = 0;
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    ListNode *cur = head, *del = head;

    while (l1 || l2 || c) //为什么要c为0呢？ 当c无法再进位，且l1和l2都为空的时候，就不需要再循环了
    {                     //即使l1和l2都走完了，C还有可能是非0，因为可能最高位要进1位才可以。

        cur->next = (ListNode *)malloc(sizeof(ListNode)); //将cur的下一个指向
        cur = cur->next;

        l1 = l1 != nullptr ? (c += l1->val, l1 = l1->next) : l1;
        l2 = l2 != nullptr ? (c += l2->val, l2 = l2->next) : l2;

        cur->val = c % 10;
        c /= 10;
    }

    head = head->next;
    cur->next = nullptr;//这里不能忘。
    free(del);
    return head;
}
