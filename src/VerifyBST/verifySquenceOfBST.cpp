//输入一个整数组，判断该数组是不是二叉树的后序遍历

#include <iostream>

using namespace std;

bool verifySquenceOfBST(int arr[], int len)
{
	if (NULL == arr || len <= 0)
	{
		cout << "input invalid" << endl;
		return false;
	}

	int root = arr[len - 1];
	int i = 0;
	for (; i < len - 1;i++)
	{
		if (arr[i] > root)
		{
			break;
		}
	}

	int j = i;
	for (; j < len - 1;j++)
	{
		if (arr[j] < root)
		{
			return false;
		}
	}

	bool left = true;
	if (i > 0)
	{
		left = verifySquenceOfBST(arr, i);
	}

	bool right = true;
	if (i < len - 1)
	{
		right = verifySquenceOfBST(arr, i);
	}

	return left && right;
}

int main()
{
	int arr1[] = { 5, 7, 6, 9, 11, 10, 8 };
	int arr2[] = { 7, 4, 6, 5 };

	cout << verifySquenceOfBST(arr2, 4)<<endl;
	cout << verifySquenceOfBST(arr1, 7)<<endl;
}