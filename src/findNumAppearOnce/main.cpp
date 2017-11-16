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

int getFirstBit(int val)
{
	return val & ~(val - 1);
}

void getTwoUniqueNum(int* arr, int len, int* num1, int* num2)
{
	if (NULL == arr || len < 2)
	{
		cout << "input invalided. " << endl;
		return;
	}

	int resultOR = 0;
	for (int i = 0; i < len; ++i)
	{
		resultOR ^= arr[i];
	}

	int diff = getFirstBit(resultOR);

	*num1 = 0;
	*num2 = 0;
	for (int i = 0; i < len; ++i)
	{
		if (arr[i] & diff)
		{
			(*num1) ^= arr[i];
		}
		else
		{
			(*num2) ^= arr[i];
		}
	}
}

void getThreeUniqueNum(int* arr, int len, int* num1, int* num2, int* num3)
{
	int resultOR = 0;
	for (int i = 0; i < len; ++i)
	{
		resultOR ^= arr[i];
	}

	int flag = 0;
	for (int i = 0; i < len; ++i)
	{
		flag ^= getFirstBit(resultOR ^ arr[i]);
	}

	flag = getFirstBit(flag);
	*num1 = 0;

	for (int i = 0; i < len;++i)
	{
		if (getFirstBit(resultOR ^ arr[i]) == flag)
		{
			(*num1) ^= arr[i];
		}
	}

	for (int i = 0; i < len; ++i)
	{
		if (arr[i] == (*num1))
		{
			int tmp = arr[i];
			arr[i] = arr[len - 1];
			arr[len - 1] = tmp;
		}
	}

	getTwoUniqueNum(arr, len - 1, num2, num3);
}

int main()
{
	int arr[9] = { 1, 11, 13, 11, 1, 13, 2, 67 ,100};
	int num1, num2,num3;
	//findeTwoNumAppearOnce(arr, 8, num1, num2);
	getThreeUniqueNum(arr, 9, &num1, &num2, &num3);
	cout << "Two number appear once is: " << endl;
	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;
}