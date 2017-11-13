#include <iostream>

using namespace std;

class Solution
{
public:
	void deleteChar(char* pSorce, const char* pDelete)
	{
		if (NULL == pSorce || NULL == pDelete)
		{
			return;
		}

		const unsigned int tableSize = 256;
		int hashTable[tableSize];
		memset(hashTable, 0, sizeof(hashTable));

		const char* pTemp = pDelete;
		while ('\0' != *pTemp)
		{
			hashTable[*pTemp] = 1;
			++pTemp;
		}

		char* pFast = pSorce;
		char* pSlow = pSorce;

		while ('\0' != *pFast)
		{
			if (1 != hashTable[*pFast])
			{
				*pSlow = *pFast;
				++ pSlow;
			}

			++ pFast;
		}

		*pSlow = '\0';
	}
};

int main()
{
	//char* pSrc = "They are students."; //全局内存变量 不允许修改  报错
	//char* pDst = "aeiou";

	char pSrc[] = "They are students.";
	char pDst[] = "aeiou";

	cout << pSrc << endl;
	cout << "after delete:" << endl;

	Solution solu;
	solu.deleteChar(pSrc, pDst);
	cout << pSrc << endl;
}