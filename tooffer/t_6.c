#include <stdio.h>
#include <string.h>

/*
Print every node's value but from tail to head.

First method, you can overturn the Linklist.
Second method, you can 
*/

typedef struct ListNode{
	int value;
	struct ListNode * next;
}ListNode;

typedef struct

void PrintListReversingly(ListNode* head);

void PrintListReversingly(ListNode* head)
{
	if(head == NULL)
		return -1;
	/*
		define three points , point at pre , current ,next ListNode.
	*/
	ListNode* pre = NULL;
	ListNode* current = head;
	ListNode* Next  = head->next;

	current = head;

	while(current->next != NULL){
		head->next = pre;
		pre = current;
		current = Next;
		Next = current->next;
	}


}

int main(){
	
}