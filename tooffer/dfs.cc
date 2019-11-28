#include <stdio.h>
#include <malloc.h>

#include <string.h>
#define MAXLIN 40

/*邻接表存储结构*/
//--------表节点存储结构-----------

typedef struct ArcNode{
	int adjvex;//表节点编号信息
	struct ArcNode *next;
}ArcNode;

//头节点存储结构
typedef struct VNode{
	char vertex[5]；//节点值
	ArcNode *link;
	int id;
}VNode；

//边节点
typedef struct Bian{
	char one[5];
	char two[5];
}Bian;

typedef struct{
	VNode adjList[MAXLIN];
	int vexnum;
	int arcnum;
	Bian bian[MAXLIN];
	int kind;
}ALGraph;

int visit[MAXLIN];

//返回是第几个顶点

int PanDuan()
{
	
}