//二维数列查找 列向递增，行向也是递增

#include <iostream>
#include <vector>

using namespace std;

bool findNum(vector<vector<int>> arr, int target)
{
	bool bResult = false;

	int rows = arr.size();
	int cols = arr[0].size();

	int j = cols - 1;
	int i = 0;

	for (; (j >= 0 && j < cols) && (i < rows && i >= 0);)
	{
		if (arr[i][j] == target )
		{
			bResult = true;
			break;
		}
		else if (arr[i][j] < target)
		{
			i++;
		}
		else
		{
			j--;
		}
	}

	return bResult;
}

int main()
{
	int a1[] = { 1, 2, 8, 9, };
	int a2[] = { 2, 4, 9, 12, };
	int a3[] = { 4, 7, 10, 13, };
	int a4[] = { 6, 8, 11, 15, };
	vector<vector<int>> array;
	array.push_back(vector<int>(a1, a1 + 4));
	array.push_back(vector<int>(a2, a2 + 4));
	array.push_back(vector<int>(a3, a3 + 4));
	array.push_back(vector<int>(a4, a4 + 4));

	if (findNum(array, 7))
	{
		cout << "7 on array" << endl;
	}

	return 0;
}