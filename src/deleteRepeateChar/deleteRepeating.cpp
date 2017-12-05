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
	int table[tableSize];
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

int main()
{
	char input[] = "google";
	char output[10];

	deleteRepeating(input, output);
	cout << output << endl;

	return 0;
}