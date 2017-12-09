//二叉树中找到和为某一值的路径

#include <iostream>
#include <vector>

using namespace std;

struct BinaryTree
{
	int value;
	BinaryTree* mLeft;
	BinaryTree* mRight;
};

void findPathCore(BinaryTree* pNode,int expectSum,vector<int>& path,int curSum)
{
	curSum += pNode->value;
	path.push_back(pNode->value);

	bool isLeaf = (pNode->mLeft == NULL) && (pNode->mLeft == NULL);
	if (curSum == expectSum && isLeaf)
	{
		cout << "A path is found: " << endl;
		auto itor = path.begin();
		for (; itor != path.end(); ++itor)
		{
			cout << *itor << " ";
		}

		cout << endl;
	}

	if (pNode->mLeft)
	{
		findPathCore(pNode->mLeft, expectSum, path, curSum);
	}

	if (pNode->mRight)
	{
		findPathCore(pNode->mRight, expectSum, path, curSum);
	}

	curSum -= pNode->value;
	path.pop_back();
}

void findPath(BinaryTree* pRoot, int excepedSum)
{
	if (NULL == pRoot)
	{
		return;
	}

	vector<int> path;
	int currSum = 0;
	findPathCore(pRoot, excepedSum, path, currSum);
}


int main()
{
	return 0;
}
