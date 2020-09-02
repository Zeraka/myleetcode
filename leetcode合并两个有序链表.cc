/*
递归法时间复杂度如何？
    为什么是O(m+n)?
    因为每次调用递归都会去掉l1或者l2的头节点，函数mergeTwolist至多会队规调用每个节点一次。所以会有
    空间复杂度也是O(m+n)因为这取决于栈的深度。递归调用需要消耗栈空间。

迭代法如何呢？

*/

struct listnode{
    int val;
    struct listnode* next;
    listnode(int x):val(x),next(nullptr){}
};

class Solution2{
    listnode* mergeTwolists(listnode*n1,listnode*n2){

    }
};

class Solution{
    listnode* mergeTwoLists(listnode* n1, listnode*n2){
        if(n1 == nullptr)  return n2;
        if(n2 == nullptr)  return n1;

        if(n1->val > n2->val){
            n2->next = mergeTwoLists(n2->next,n1);
            return n2;
        }else{
            n1->next = mergeTwoLists(n1->next,n2);
            return n1;
        }

    }
};
/*
class Solution{
    listnode* mergeTwoLists(listnode* n1,listnode*n2){
        if(n1 == nullptr )  return n2;
        if(n2 == nullptr) return n1;
        listnode* head;

        if(n1->val < n2->val){
            head = n1;
            head->next = mergeTwoLists(n1->next,n2);
        }else{
            head = n2;
            head->next = mergeTwoLists(n1,n2->next);
        }

        return head;
    }
};
*/