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
Linklist* joinLinklist(Linklist* node1, Linklist* node2);

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

Linklist* joinLinklist(Linklist* node1, Linklist* node2)
{
	Linklist* p1 = node1;
	Linklist* p2 = node2;
	Linklist* p3 = 0;

		if( p1->value < p2->value)
		{
			p3 = p1;
			p3->next = p2;
			p1 = p1->next;
		}else{
			p3 = p2;
			p2 = p2->next;
		}


	while(){
		if( p1->value < p2->value)
		{
			p1
		}
	}

	return p3;
}


int main()
{
	/* code */
	int a[]={1,3,5,7};
	int b[]={2,4,6,8};
	Linklist*node1 = 0;
	Linklist*node2 = 0;
	Linklist* node3 = 0;

	CreatIntLinkList(a, node1, 4);
	CreatIntLinkList(b,node2, 4);
	node3 = joinLinklist(node1, node2);

	PrintLinklist(node3);

	DeleteIntLinkList(node3);
	DeleteIntLinkList(node1);
	DeleteIntLinkList(node2);
	return 0;
}