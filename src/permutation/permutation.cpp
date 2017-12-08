//输出字符的全排列
//input:abc
//output:abc acb bac bca cab cba

#include <iostream>

using namespace std;

void permutationCore(char* pStr, char* pBegin);

void permutation(char* pStr)
{
	if (NULL == pStr)
	{
		return;
	}

	permutationCore(pStr, pStr);
}

void permutationCore(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
	{
		cout << pStr << endl;
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++ pCh)
		{
			char tmp = *pCh;
			*pCh = *pBegin;
			*pBegin = tmp;

			permutationCore(pStr, pBegin + 1);

			tmp = *pCh; //回复回去
			*pCh = *pBegin;
			*pBegin = tmp;
		}
	}
}

int main()
{
	char arr[] = "abc";
	permutation(arr);
}