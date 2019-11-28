//raw to offer 32
//从上到下打印二叉树
/*
从上到下打印二叉树，就是binaryTree的
"广度优先遍历"，
先用递归的方式打印
*/
#include<deque>


void PrintFromTopToBottom(BTNode * root);

int main()
{

}

//从上到下打印二叉树
void PrintFromTopToBottom(BTNode * root){
	if(root == null)
		return 1;

	std::deque<BTNode*> dequeNode;
	dequeNode.push_back(root)；//加入队列

	while(dequeNode.size() != NULL)
	{
		BTNode* pnode = dequeNode.front();//把队列首部赋给节点
		dequeNode.pop_front();//弹出首部
		//打印节点值
		printf("%d", pnode->nvalue);

		if(pnode->lnode != NULL)
			dequeNode.push_back(pnode->lnode);
		if(pnode->rnode != NULL)
			dequeNode.push_back(pnode->rnode);
	}


}

//分行从上到下打印二叉树
//加入状态机制，
void PrintFromTopToBottom_n(BTNode* root)
{
	BTNode* pnode = root;

	if(pnode == NULL)
		return 1;

	std::deque<BTNode*> dequeNode;

	dequeNode.push(pnode);

	int nextlevel = 0;//下一层节点的数
	int toBePrint = 1;//当前层中没有被打印的节点数

	while(!dequeNode){
		BTNode* pnode = dequeNode.front();
		printf("%d", pnode->nvalue);

		if(pnode->lnode != null)
			{
				dequeNode.pop(pnode->lnode);
				++nextlevel;
			}

		if(pnode->rnode != null)
		{
			dequeNode.pop(pnode->rnode);
			++nextlevel;
		}

		dequeNode.pop();
		--toBePrint;

		if(toBePrint == 0)
		{
			printf("\n" );
			toBePrint = nextlevel;
			nextlevel = 0;
		}


	}


}