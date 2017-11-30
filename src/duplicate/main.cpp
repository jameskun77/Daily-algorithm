#include <iostream>
#include <set>

using namespace std;

bool checkValid(int* arr, int len)
{
	if (NULL == arr || len < 0)
	{
		return false;
	}

	for (int i = 0; i < len; ++i)
	{
		if (arr[i] > len - 1 || arr[i] < 0)
		{
			return false;
		}
	}

	return true;
}

bool duplication(int arr[], int len, int* duplicate)
{
	*duplicate = -1;
	bool isDup = false;
	if(!checkValid(arr,len))
	{
		cout << "invalid input" << endl;
		return false;
	}

	set<int> intSet;
	for (int i = 0; i < len; ++i)
	{
		if (intSet.count(arr[i]) == 1)
		{
			*duplicate = arr[i];
			isDup = true;
			break;
		}

		intSet.insert(arr[i]);
	}
}

int main()
{
	int result;

	int array[] = { 2, 3, 1, 0, 2, 5, 3 };
	if (duplication(array, 7, &result))
	{
		cout << result << endl;
	}
}