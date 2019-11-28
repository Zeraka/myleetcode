#ifndef __UTIL_BINARYTREE_H__
#define __UTIL_BINARYTREE_H__

/*
implement a binary tree that can store any class data.

*/

typedef void* ElemType;
typedef struct BitreeNode_t
{
	ElemType data;
	struct bitreeNode_t *left;
	struct bitreeNode_t *right;
}BitreeNode;

typedef struct BiTree_t{
	int length;
	int width;
	struct bitreeNode_t * root;

}BiTree;

int BiTreeCreate();//
int BiTreeInsert();




//preorder traversal



#endif