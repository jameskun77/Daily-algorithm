//分层打印二叉树

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct BinaryTree
{
	int value;
	BinaryTree* mLeft;
	BinaryTree* mRight;
};

BinaryTree* reConstruct(vector<int> preorder, vector<int> inorder)
{
	if (preorder.size() != inorder.size())
	{
		cout << "input invalid" << endl;
		return NULL;
	}

	//len can not 0
	int size = preorder.size();
	if (size == 0)
	{
		cout << "input size is zero" << endl;
		return NULL;
	}

	int value = preorder[0];
	BinaryTree* pRoot = new BinaryTree();
	pRoot->value = value;

	//inorder find rootindex
	int rootIndex = 0;
	int len = preorder.size();
	for (rootIndex = 0; rootIndex < len;rootIndex++)
	{
		if (inorder[rootIndex] == value)
		{
			cout << "find the root at " << rootIndex << " in inorder" << endl;
			break;
		}
	}

	if (rootIndex > len)
	{
		cout << "can not find root value: " << value << "in inorder" << endl;
		return NULL;
	}

	//区分左右子树
	int leftLen = rootIndex;
	int rightLen = len - 1 - rootIndex;
	vector<int> preLeft(leftLen), inLeft(leftLen);
	vector<int> preRight(rightLen), inRight(rightLen);

	for (int i = 0; i < len; i++)
	{
		if (i < rootIndex)
		{
			preLeft[i] = preorder[i + 1];
			inLeft[i] = inorder[i];
		}
		else if (i > rootIndex)
		{
			preRight[i-rootIndex-1] = preorder[i];
			inRight[i-rootIndex -1] = inorder[i];
		}
	}

	pRoot->mLeft = reConstruct(preLeft, inLeft);
	pRoot->mRight = reConstruct(preRight, inRight);

	return pRoot;
}

void printFromToptoBottom(BinaryTree* pTree)
{
	if (NULL == pTree)
	{
		cout << "input is NULL" << endl;
		return;
	}

	deque<BinaryTree *> treeDeque;
	treeDeque.push_back(pTree);

	while (!treeDeque.empty())
	{
		BinaryTree* pTreeNode = treeDeque.front();
		treeDeque.pop_front();

		cout << pTreeNode->value;
		
		if (pTreeNode->mLeft)
		{
			treeDeque.push_back(pTreeNode->mLeft);
		}
		
		if (pTreeNode->mRight)
		{
			treeDeque.push_back(pTreeNode->mRight);
		}
	}
}

int main()
{
	int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	vector<int> preOrder(pre, pre + 8);
	vector<int>  inOrder(in, in + 8);

	BinaryTree *root = reConstruct(preOrder, inOrder);
	printFromToptoBottom(root);

	return 0;
}