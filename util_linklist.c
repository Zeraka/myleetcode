#include "util_linklist.h"
#include "util_log.h"

//create a node
static ChainNode * NewChainNode(ElemType data)
{
	if(data == NULL)
	{
		ERROR_LOGGER("the data is null\n");
		return ERROR;
	}

	ChainNode* pChain = 0;
	pChain = (ChainNode *)malloc(sizeof(ChainNode));

	pChain->data = data;
	pChain->next = 0; //指向下一个节点为0

	return pChain;
}

//create a Linklist
Linklist* ListCreate(int size)
{
	Linklist* llt = 0;
	ElemType data = 0;
	int linksize = 0;
	//分配一个内存区域，并且用指针指向之。由于类型已经分配好了，就不用复制了
	llt = (Linklist*)malloc(sizeof(List));

	//memset(llt);
	if(size < 2){
		INFO_LOGGER("the size must be larger than 2;\n");
		return ERROR;
	}

	if(llt == NULL)
	{
		ERROR_LOGGER("create linklist failed\n");
		return ERROR;
	} 

	llt->head = NewChainNode(data);//一定要有头节点，必须要有头节点
	
	if(llt->head == NULL)
	{
		free(llt);
		return ERROR;
	}

	llt->Nodesize = size;
	llt->tail = llt->head;//指向的节点
	llt->Linksize = linksize;
	return llt;
}


int ListDestory(Linklist* linklist){

}

//append a node in tail
void ListAppend(Linklist* linklist, ...)
{	
	ChainNode* newNode = 0;
	void * data = 0; //设立一个可以指向任何数据类型的指针
	void * pos = 0;//用于指向第二个参数的地址
	int size = 0;
	pos = &linklist + 1;
	if(pos == NULL || linklist->head == NULL)
		return ERROR;

	data = (void *)malloc(sizeof(linklist->Nodesize));//具体指向的空间大小要确定
	if(data == NULL)
	{
		return ERROR;
	}

	memcpy(data,pos,linklist->Nodesize);
	newNode = NewChainNode(data);

	if(newNode == 0)
		return ERROR;

	linklist->tail->next = newNode;
	linklist->tail = newNode;
	newNode->next = 0; //一定要指向空
	linklist->Linksize += 1;

	return SUCCESS;
}

/*
插入元素，可以在任何一个位置，
*/
void ListInsert(Linklist* linklist, int index, ...){

	int i=0;
	ChainNode* pnode = 0;
	ChainNode* Newnode = 0;
	void * pos = &linklist + 2;
	void * data = 0;

	if(linklist == NULL){
		ERROR_LOGGER("linklist is null\n");
		return ERROR;
	}

	if(linklist->linksize < index){
		ERROR_LOGGER("the size you input is too big\n");
		return ERROR;
	}

	if(index < 0)
	{
		ERROR_LOGGER("index must >=0\n");
		return ERROR;
	}

	data = (void *)malloc(sizeof(linklist->Nodesize));
	if(!data)	return ERROR;

	memcpy(data, pos, linklist->Nodesize);

	newNode = NewChainNode(data);

	pnode = linklist->head;
	if(!pnode )
		return ERROR;

	while(i < index){
		pnode = pnode->next;
		i++;
	}

	Newnode->next = pnode->next;
	pnode->next = Newnode;

	return SUCCESS;
}

/*
删除元素,从尾部删除
*/
int ListDeleteDataLast(Linklist* mylist)
{
	Linklist* pnode = 0;
	Linklist* Newnode = 0;

	pnode = mylist->head;

	if(pnode == NULL)	return ERROR;

	while(pnode != NULL)
	{	
		Newnode = pnode;
		pnode = pnode->next;

	}

	Newnode->next = NULL;
	mylist.Linksize -= 1;
	mylist->tail = Newnode;

	//delete the node ;
	free(pnode);

	return SUCCESS;
}


/*删除元素，从头部删除*/
int ListDeleteDataHead(Linklist* mylist)
{
	Linklist * pnode = 0;
	Linklist * dnode = 0;

	pnode = mylist->head;

	mylist->head = pnode->next;
	pnode->next = NULL;

	free(pnode->data);
	free(pnode);

	return SUCCESS;
}


/*
Calculate the length of list
*/
int Listlength(Linklist* linklist){
	int size = 0;
	ChainNode* node = 0;
	if(linklist == NULL || linklist->head == NULL)
		return ERROR;

	node = linklist->head->next;

	while(node!= NULL)
	{
		node = node->next;
		size++;
	}

	if(size != linklist.Linksize){
		INFO_LOGGER("the size of link is wrong,the wrong size"
					"the wrong size is %d and the true is %d\n",
					Linksize, size);
	}

	return size;
}



//========================
//test Unit===============
//========================
#if UNITTEST
int main(){

	struct testNode_t{
		int number;
	}testNode;

	//创建节点
	ListCreate(sizeof(testNode));
}

#endif
