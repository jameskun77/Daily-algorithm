//统计一个数字在排序数组中出现的次数
//｛1，2，3，3，3，3，4，5｝和数字3，输出4

#include <iostream>

using namespace std;

int getFirstK(int arr[], int len, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int minIndex = (start + end) / 2;
	int minData = arr[minIndex];

	if (minData == k)
	{
		if ((minIndex > 0 && arr[minIndex - 1] != k) || (minIndex == 0))
		{
			return minIndex;
		}
		else
		{
			end = minIndex - 1;
		}
	}
	else if (minData > k)
		end = minIndex - 1;
	else
		start = minIndex + 1;

	return getFirstK(arr, len, k, start, end);
}

int getLastK(int arr[], int len, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int minIndex = (start + end) / 2;
	int minData = arr[minIndex];

	if (minData == k)
	{
		if ((minIndex < len - 1 && arr[minIndex + 1] != k) || (minIndex == len - 1))
		{
			return minIndex;
		}
		else
		{
			start = minIndex + 1;
		}
	}
	else if (minIndex > k)
		end = minIndex - 1;
	else
		start = minIndex + 1;

	return getLastK(arr, len, k, start, end);
}

int getNumberOfK(int* data, int len, int k)
{
	int number = 0;
	if (data != NULL && len > 0)
	{
		int first = getFirstK(data, len, k, 0, len - 1);
		int end = getLastK(data, len, k, 0, len - 1);

		if (first != -1 && end != -1)
		{
			number = end - first + 1;
		}
	}

	return number;
}

int main()
{
	int arr[8] = { 1,2,3,3,3,3,4,5 };
	cout << getNumberOfK(arr, 8, 3);
}