#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Linklist{
	int value;
	struct Linklist* next;
}Linklist;

int CreatIntLinkList(int array[], Linklist* node, int length);
int PrintLinklist(Linklist*node);
int DeleteIntLinkList(Linklist* node);

int PrintLinklist(Linklist* node)
{
	Linklist* p = node;
	while(p != NULL)
	{
		printf("%d\n",p->value);
		p = p->next;
	}
	return 1;
}


int CreatIntLinkList(int array[], Linklist* node,int length){
	int i = 0;
	node = (Linklist*)malloc(sizeof(Linklist));
	memset(node, 0, sizeof(Linklist));

	Linklist* p = node;
	for(i=0;i< length ;i++)
	{
		p->value = array[i];
		if(i < length -1){
			p->next = (Linklist*)malloc(sizeof(Linklist));
			memset(p->next, 0, sizeof(Linklist));
			p = p->next;
		}
	}
	PrintLinklist(node);
}

int DeleteIntLinkList(Linklist* node)
{	
	Linklist* tmp;
	while(node){
		tmp = node->next;
		free(node);
		node = tmp;
	}
	return 0;

}

int main()
{
	
}