//树的子结构

#include <iostream>

using namespace std;

struct BinaryTree
{
	int value;
	BinaryTree* mLeft;
	BinaryTree* mRight;
};

bool tree1HaveTree2(BinaryTree* ptree1, BinaryTree* pTree2);

bool hasSubTree(BinaryTree* pRoot1, BinaryTree* pRoot2)
{
	bool result = false;
	if (NULL != pRoot1 && NULL != pRoot2)
	{
		if (pRoot1->value == pRoot2->value)
		{
			result = tree1HaveTree2(pRoot1, pRoot2);
		}

		if (!result)
		{
			result = tree1HaveTree2(pRoot1->mLeft, pRoot2);
		}

		if (!result)
		{
			result = tree1HaveTree2(pRoot1->mRight, pRoot2);
		}
	}

	return result;
}

bool tree1HaveTree2(BinaryTree* ptree1, BinaryTree* pTree2)
{
	if (pTree2 == NULL)
	{
		return true;
	}
	
	if (ptree1 == NULL)
	{
		return false;
	}

	if (ptree1->value != pTree2->value)
	{
		return false;
	}

	return tree1HaveTree2(ptree1->mLeft, pTree2->mLeft) && tree1HaveTree2(ptree1->mRight, pTree2->mRight);
}