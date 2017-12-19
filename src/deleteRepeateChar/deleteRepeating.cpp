//删除字符串中重复出现的数字
//输入google，输出gole

#include <iostream>

using namespace std;

void deleteRepeating(char* pSorce,char* pOut)
{
	if (NULL == pSorce)
	{
		cout << "input is null" << endl;
		return;
	}

	const int tableSize = 256;
	char table[tableSize];
	for (int i = 0; i < tableSize; ++i)
	{
		table[i] = 0;
	}

	char* pChar = pSorce;
	while ('\0' != *pChar)
	{
		table[*pChar]++;
		pChar++;
	}

	pChar = pSorce;
	int count = 0;
	while ('\0' != *pChar)
	{
		if (table[*pChar] == 1)
		{
			pOut[count++] = *pChar;
		}
		else if (table[*pChar] > 1)
		{
			pOut[count++] = *pChar;
			table[*pChar] = 0;
		}
		pChar++;
	}

	pOut[count++] = '\0';
}

void deleteRepeating(char* pSorce)
{
	if (NULL == pSorce)
	{
		cout << "input is null" << endl;
		return;
	}

	const int tableSize = 256;
	char table[tableSize];
	for (int i = 0; i < tableSize; ++i)
	{
		table[i] = 0;
	}

	char* pChar = pSorce;
	while ('\0' != *pChar)
	{
		table[*pChar]++;
		pChar++;
	}

	char* pFast = pSorce;
	char* pSlow = pSorce;
	while ('\0' != *pFast)
	{
		if (table[*pFast] == 1)
		{
			*pSlow = *pFast;
			pSlow++;
		}
		else if (table[*pFast] > 1)
		{
			*pSlow = *pFast;
			table[*pFast] = 0;
			pSlow++;
		}

		++pFast;
	}

	*pSlow = '\0';
	
}

int main()
{
	char input[] = "google";
	char output[10];

	//deleteRepeating(input, output);
	deleteRepeating(input);
	cout << input << endl;

	return 0;
}