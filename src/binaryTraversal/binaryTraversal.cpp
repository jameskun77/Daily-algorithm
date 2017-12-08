//¶þ²æÊ÷±éÀú

#include <iostream>
#include <stack>

using namespace std;

struct BinaryTree
{
	int val;
	BinaryTree* mLeft;
	BinaryTree* mRight;
};

void preOrder_recursion(BinaryTree* pNode)
{
	if (pNode)
	{
		cout << pNode->val << " ";
		preOrder_recursion(pNode->mLeft);
		preOrder_recursion(pNode->mRight);
	}
}

void preOrder(BinaryTree* pNode)
{
	if (pNode == NULL)
	{
		return;
	}

	BinaryTree* pTree = pNode;
	stack<BinaryTree* > treeStack;

	while (NULL != pTree || !treeStack.empty() )
	{
		while (NULL != pTree)
		{
			cout << pTree->val << "\t";
			treeStack.push(pTree);
			pTree = pTree->mLeft;
		}

		if (!treeStack.empty())
		{
			pTree = treeStack.top();
			treeStack.pop();
			pTree = pTree->mRight;
		}
	}
}

void inOrder_recursion(BinaryTree* pNode)
{
	if (pNode)
	{
		inOrder_recursion(pNode->mLeft);
		cout << pNode->val << " ";
		inOrder_recursion(pNode->mRight);
	}
}

void inOrder(BinaryTree* pNode)
{
	if (NULL == pNode)
	{
		return;
	}

	stack<BinaryTree* > treeStack;
	BinaryTree* pTree = pNode;

	while (NULL != pTree || !treeStack.empty())
	{
		while (NULL != pTree)
		{
			treeStack.push(pTree);
			pTree->mLeft;
		}

		if (!treeStack.empty())
		{
			pTree = treeStack.top();
			treeStack.pop();
			cout << pTree->val << "\t";
			pTree = pTree->mRight;
		}
	}
}

void postOrder_recursion(BinaryTree* pNode)
{
	if (pNode)
	{
		postOrder_recursion(pNode->mLeft);
		postOrder_recursion(pNode->mRight);
		cout << pNode->val << " ";
	}
}

void postOrder(BinaryTree* pNode)
{
	if (NULL == pNode)
	{
		return;
	}

	BinaryTree* cur;
	BinaryTree* pre = NULL;
	stack<BinaryTree* > treeStack;
	treeStack.push(pNode);

	while (!treeStack.empty())
	{
		cur = treeStack.top();
		if ((cur->mLeft == NULL && cur->mRight == NULL) || 
			(pre != NULL && (cur->mLeft == pre || cur->mRight == pre)))
		{
			cout << cur->val << "\t";
			treeStack.pop();
			pre = cur;
		}
		else
		{
			//stack push right
			if (cur->mRight)
			{
				treeStack.push(cur->mRight);
			}

			if (cur->mLeft)
			{
				treeStack.push(cur->mLeft);
			}
		}

	}
}