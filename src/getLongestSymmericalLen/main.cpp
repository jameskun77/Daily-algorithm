#include <iostream>

using namespace std;

bool isSymmetrical(char* pBegin, char* pEnd)
{
	if (NULL == pBegin || NULL == pEnd || pBegin > pEnd)
	{
		return false;
	}

	while (pBegin < pEnd)
	{
		if (*pBegin != *pEnd)
			return false;

		++pBegin;
		--pEnd;
	}

	return true;
}

int getLongestSymmetrical(char* pString)
{
	if (NULL == pString)
	{
		return 0;
	}

	int symmetricalLen = 1;

	char* pFirst = pString;
	int len = strlen(pString);

	while (pFirst < &pString[len - 1])
	{
		char* pLast = pFirst + 1;
		while (pLast <= &pString[len - 1])
		{
			if (isSymmetrical(pFirst,pLast))
			{
				int tmpSymmetricalLen = pLast - pFirst + 1;
				if (tmpSymmetricalLen > symmetricalLen)
				{
					symmetricalLen = tmpSymmetricalLen;
				}

			}
			
			pLast++;
		}

		pFirst++;
	}

	return symmetricalLen;
}

int main()
{
	//char* pChar = "google";
	char* pChar = "googgoog";
	cout << "Longest symmetrical: " << endl;
	cout << getLongestSymmetrical(pChar) << endl;
}