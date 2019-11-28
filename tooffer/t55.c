
int DepthOfBTree(tnode * root)
{
	if(root == null)
	{
		return 0;
	}

	if(root->left)
	{
		int nLeft = DepthOfBTree(root->left);
	}

	if(root->right)
	{
		int nright = DepthOfBTree(root->right);
	}

	return (nLeft > nright)?(nLeft + 1)(nright + 1);
}

//判断是否是平衡二叉树
bool IsBalanced(BinaryTreeNode *pRoot, int* pDepth)
{
	if(pRoot == nullptr)
	{
		*pDepth = 0;
		return true;
	}

	int left, right;

	if(IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right))
	{
		int diff = left -right;

		if(diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right ? left:right);
			return true;
		}


	}

	return false;
}

//把叶节点当作左右子节点都为空的