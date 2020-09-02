/*
此题头条考过，
首先是要将两个链表反转。
然后再进行两数相加。得到的链表再次反转得到最后的值。
*/

typedef struct listnode{
    struct listnode* next;
    int val;
}listnode;

listnode* addTwoNumbers(listnode* n1,listnode *n2){
    listnode* n3 = reverselist(n1);
    listnode* n4 = reverselist(n2);
    listnode* head = (listnode*)malloc(sizeof(listnode));

    listnode *del =head, *cur = head;
    int c = 0;

    while(n3||n4||c){
        n3 = n3!=nullptr?(c+=n3->val,n3 = n3->next):n3;
        n4 = n4!=nullptr?(c+=n4->val,n4=n4->next):n4;

        cur->next = (listnode*)malloc(sizeof(listnode));
        cur = cur->next;
        cur->val = c%10;
        c /= 10;
    }

    head = head->next;
    cur->next = nullptr;
    free(del);

    return reverselist(head);


}

listnode* reverselist(listnode* head){
    if(head == nullptr || head->next == nullptr)  return head;

    listnode* res;

    //
    res  =  reverselist(head->next);

    head->next->next = head;
    head->next = nullptr;

    return res;
}

//