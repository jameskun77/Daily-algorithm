//Çó¶þ²æÊ÷¾µÏñ
//		 8                                        8                 
//		/ \                                      / \
//     6   10     --->                          10  6  
//    /\   /\                                  /\   /\
//   5  7 9  11                               11 9 7  5 
#include <iostream>
#include <queue>

using namespace std;

struct BinaryTree
{
	int value;
	BinaryTree* mLeft;
	BinaryTree* mRight;
};

void swap(int& a, int& b)
{
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
}


void MirrorRecursive(BinaryTree* pTree)
{
	if (NULL == pTree)
	{
		return;
	}

	if (NULL == pTree->mLeft && NULL == pTree->mRight)
	{
		return;
	}

	BinaryTree* tmp = pTree->mLeft;
	pTree->mLeft = pTree->mRight;
	pTree->mRight = pTree->mLeft;

	if (pTree->mLeft)
	{
		MirrorRecursive(pTree->mLeft);
	}

	if (pTree->mRight)
	{
		MirrorRecursive(pTree->mRight);
	}
}

void MirrorPre(BinaryTree* pTree)
{
	if (NULL == pTree)
	{
		return;
	}

	if (NULL == pTree->mLeft && NULL == pTree->mRight)
	{
		return;
	}

	queue<BinaryTree *> binaryTreeQueue;
	BinaryTree* pNode = pTree;

	while (pNode)
	{
		swap(pNode->mLeft, pNode->mRight);
		if (pNode->mLeft)
			binaryTreeQueue.push(pNode->mLeft);

		if (pNode->mRight)
			binaryTreeQueue.push(pNode->mRight);

		if (!binaryTreeQueue.empty())
		{
			pNode = binaryTreeQueue.front();
			binaryTreeQueue.pop();
		}
		else
		{
			break;
		}
	}
}