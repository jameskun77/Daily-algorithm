#include <iostream>

using namespace std;

struct BinaryTree
{
	int value;
	BinaryTree* mLeft;
	BinaryTree* mRight;
};

int TreeDepth(BinaryTree* pNode)
{
	if (NULL == pNode)
	{
		return 0;
	}
	
	int leftLen = TreeDepth(pNode->mLeft);

	int rightLen = TreeDepth(pNode->mRight);

	return (leftLen > rightLen) ? leftLen + 1 : rightLen + 1;

}

bool isBalance(BinaryTree* pNode)
{
	if (pNode == NULL)
	{
		return true;
	}

	int leftLen = TreeDepth(pNode->mLeft);

	int rightLen = TreeDepth(pNode->mRight);

	int diff = leftLen - rightLen;
	if (diff > 1 || diff < -1)
	{
		return false;
	}

	return isBalance(pNode->mLeft) && isBalance(pNode->mRight);
}

bool isBalanceCore(BinaryTree* pRoot,int* pDepth)
{
	if (NULL == pRoot)
	{
		*pDepth = 0;
		return true;
	}

	int left, right;
	if (isBalanceCore(pRoot->mLeft, &left) && isBalanceCore(pRoot->mRight, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}

bool isBalance1(BinaryTree* pRoot)
{
	int depth;
	return isBalanceCore(pRoot, &depth);
}