#include <iostream>

using namespace std;

int findGreatestSumOfSubArr(int* pNum, int len)
{
	if (len <= 0)
	{
		cout << "invalided input" << endl;
		return -1;
	}

	int currentSum,GreatestSum;
	currentSum = GreatestSum = 0;

	for (int i = 0; i < len; ++i)
	{
		currentSum += pNum[i];

		if (currentSum < 0)
		{
			currentSum = 0;
		}

		if (currentSum > GreatestSum)
		{
			GreatestSum = currentSum;
		}

	}

	//都是负数
	if (GreatestSum == 0)
	{
		GreatestSum = pNum[0];
		for (int i = 1; i < len; ++i)
		{
			if (pNum[i] > GreatestSum)
			{
				GreatestSum = pNum[i];
			}
		}
	}

	return GreatestSum;

}

int main()
{
	int arr[8] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int arr1[5] = { -12, -5, -3,-8,-4 };
	cout << findGreatestSumOfSubArr(arr, 8) << endl;
	cout << findGreatestSumOfSubArr(arr1, 5) << endl;
}