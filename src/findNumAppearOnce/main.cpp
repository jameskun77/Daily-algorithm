#include <iostream>

using namespace std;

int findFirstBitIs1(int val)
{
	int indexBit = 0;
	while ((val & 1) == 0 && indexBit < 32)
	{
		val = val >> 1;
		indexBit++;
	}

	return indexBit;
}

bool isBit1(int val, int indexBit)
{
	val = val >> indexBit;
	return (val & 1);
}

void findeTwoNumAppearOnce(int* pArr,int len,int& num1,int& num2)
{
	if (NULL == pArr || len < 2)
	{
		cout << "invalided input" << endl;
		return;
	}

	int resultOR = 0;
	for (int i = 0; i < len; ++i)
	{
		resultOR ^= pArr[i];
	}

	int indexBit = findFirstBitIs1(resultOR);

	num1 = num2 = 0;

	for (int i = 0; i < len; ++i)
	{
		if (isBit1(pArr[i],indexBit))
		{
			num1 ^= pArr[i];
		}
		else
		{
			num2 ^= pArr[i];
		}
	}

}

int main()
{
	int arr[8] = { 1, 11, 13, 11, 1, 13, 2, 67 };
	int num1, num2;
	findeTwoNumAppearOnce(arr, 8, num1, num2);
	cout << "Two number appear once is: " << endl;
	cout << num1 << endl;
	cout << num2 << endl;
}