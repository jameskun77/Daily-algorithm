#include <iostream>

using namespace std;

struct BinaryTree
{
	int val;
	BinaryTree* mLeft;
	BinaryTree* mRight;
};

//返回二叉树第K层 节点的个数
int getBTreeKthLevelNodesTotal(BinaryTree* pRoot, int KthLevel)
{
	if (NULL == pRoot || KthLevel <= 0)
	{
		return 0;
	}

	if (NULL != pRoot && KthLevel == 1)
	{
		return 1;
	}

	return getBTreeKthLevelNodesTotal(pRoot->mLeft, KthLevel - 1) + getBTreeKthLevelNodesTotal(pRoot->mRight, KthLevel - 1);
}

//返回二叉树第K层 叶子的个数

int getBTreeKthLevelLeafTotal(BinaryTree* pRoot, int KthLevel)
{
	if (pRoot == NULL || KthLevel <= 0)
	{
		return 0;
	}

	if (pRoot != NULL && KthLevel == 1)
	{
		if (pRoot->mLeft == NULL && pRoot->mRight == NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	return getBTreeKthLevelLeafTotal(pRoot->mLeft, KthLevel - 1) + getBTreeKthLevelLeafTotal(pRoot->mRight, KthLevel - 1);
}