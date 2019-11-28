#ifndef __UTIL_LINKLIST_H__
#define __UTIL_LINKLIST_H__

#define 

typedef void * ElemType;
 
typedef struct Node_t{
	ElemType data;
	struct Node_t * Next;
}ChainNode;

typedef struct Linklist_t {

	struct Node_t * head;
	int Nodesize;
	struct Node_t * tail;
	int Linksize;



	/*
	void (*set)(Node *);
	void (*get)();
	void (*push)(void);
	void (*pop)(void);
	void (*length)(void);
	*/
} Linklist;

void ListAppend(Linklist* linklist, ...);
void ListInsert(Linklist* linklist, int, ...);

int ListDeleteDataLast(Linklist*);


//make a data become a ChainNode
static ChainNode * NewChainNode(ElemType data);
//accept any class data
Linklist* ListCreate(int size);

//
void ListAppend(Linklist* linklist, ...);
//

void ListPop(Linklist* linklist);


//calculate the length of the list
int Listlength(Linklist* linklist);

void DeleteLink();


#endif