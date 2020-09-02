/*
两个链表求和
得到一个新链表

*/
struct ListNode{
    int val;
    ListNode* left;
    ListNode* right;
    ListNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr ) return nullptr;

        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        ListNode* del = head;
        int c = 0;

        while(l1||l2||c)
        {
            cur->next = new ListNode(0);
            cur = cur->next;
            l1 = (l1 != nullptr)?(c+=l1->val,l1=l1->next):l1;
            l2 = (l2 != nullptr)?(c+=l2->val,l2=l2->next):l2;
            cur->val = c%10;
            c/=10;
        }

        head = head->next;
        cur->next = nullptr;
        
        delete del;
        return head;
    }
};