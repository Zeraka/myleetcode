#include <stdio.h>

/*
Delete a node in the Linklist.
*/

typedef struct Linklist{
	int value;
	struct Linklist* next;
}Linklist;

int DeleteANode(Linklist* root, Linklist* DeletedNode);

int DeleteANode(Linklist* root, Linklist* DeletedNode)
{
	if(root == NULL || DeletedNode == NULL)
	{
		return -1;
	}
	else if(DeletedNode->next == NULL)
	{
		return -2;
	}
	
	Linklist* p = DeletedNode->next;
	DeletedNode->value = DeletedNode->next->value;
	DeletedNode->next = DeletedNode->next->next;

	free(p);

}