#include <iostream>

using namespace std;

int binarySearch(int arr[], int len, int num)
{
	if (arr == NULL || len <= 0)
	{
		cout << "input invalid" << endl;
		return -1;
	}

	int low = 0;
	int high = len - 1;

	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == num)
		{
			return mid;
		}
		else if (arr[mid] > num)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return -1;
}

int binarySearch_Recursive(int arr[], int low,int high, int num)
{
	if (arr == NULL)
	{
		cout << "input invalid" << endl;
		return -1;
	}


	if (low > high)
		return -1;

	int mid = low + (high - low) / 2;
	if (arr[mid] == num)
		return mid;
	else if (arr[mid] > num)
		return binarySearch_Recursive(arr, low, mid - 1, num);
	else
		return binarySearch_Recursive(arr, mid + 1, high, num);
}

int main()
{
	int i, j;
	int arr[10];
	for (i = 0; i < 10; i++)
	{
		arr[i] = i * 2;
	}
	cout << "Input the search number:";
	cin >> j;
	int location = binarySearch(arr, 10, j);
	if (location != -1)
		cout << "Exist1:" << location << endl;
	else
		cout << "Not existed in array!" << endl;
	location = binarySearch_Recursive(arr, 0, 9, j);
	if (location != -1)
		cout << "Exist2:" << location << endl;
	else
		cout << "Not existed in array!" << endl;
	system("pause");
	return 0;
}