//二叉树求路径的值
void FindPath(BinaryTreeNode* pRoot, int expecttedSum, std::vector<int>& path, int currentSum)
{
	currentSum += pRoot->m_nvalue;
	path.push_back(pRoot->m_nvalue);//把每次的根节点放到栈里面去。

	//如果是叶节点，并且路径上节点值的和等于输入的值，
	//则打印出这条路径
	bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;

	if(currentSum == expecttedSum && isLeaf)
	{
		printf("A path is found");
		std::vector<int>::iterator iter = path.begin();
		for(; iter == path.end(); iter++)
		{
			
		}

	}
}