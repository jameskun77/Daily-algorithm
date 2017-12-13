#include <iostream>

using namespace std;

struct BinaryTree
{
	int val;
	BinaryTree* mLeft;
	BinaryTree* mRight;
};

//���ض�������K�� �ڵ�ĸ���
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

//���ض�������K�� Ҷ�ӵĸ���

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