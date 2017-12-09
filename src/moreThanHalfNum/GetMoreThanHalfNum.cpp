//获取数组中超过数组长度一般的成员

#include <iostream>

using namespace std;

bool g_invalidedInput = false;

int getMoreThanHalfNum(int* pNum, int len)
{
	if (NULL == pNum || len <= 0)
	{
		g_invalidedInput = true;
		return 0;
	}

	int result = pNum[0];
	int count = 1;

	for (int i = 1; i < len; ++i)
	{
		if (0 == count)
		{
			result = pNum[i];
			count = 1;
		}
		else if (pNum[i] != result)
		{
			--count;
		}
		else
		{
			++count;
		}
	}

	//check input 
	count = 0;
	for (int i = 0; i < len;++i)
	{
		if (pNum[i] == result)
		{
			++count;
		}
	}

	if (count* 2 < len)
	{
		g_invalidedInput = true;
		return 0;
	}

	return result;
}

int main()
{
	int a[10] = { 3, 5, 7, 11, 5, 5, 5, 4, 5, 5 };
	cout << getMoreThanHalfNum(a, 10) << endl;
}