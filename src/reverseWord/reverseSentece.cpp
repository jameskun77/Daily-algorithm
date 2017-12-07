//输入一个英文句子，翻转句子中单词的顺序
//intput: "I am a student."
//output: "student. a am I"

#include<iostream>

using namespace std;

void reverse(char* pBegin, char* pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
	{
		return;
	}

	while (pBegin < pEnd)
	{
		char tmp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = tmp;

		pBegin++;
		pEnd--;
	}
}

char* reverseSentence(char* pData)
{
	if (pData == NULL)
	{
		return NULL;
	}

	char* pBegin = pData;
	char* pEnd = pData;
	while (*pEnd != '\0')
	{
		pEnd++;
	}

	pEnd--;
	
	reverse(pBegin, pEnd);
	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			++pBegin;
			++pEnd;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}

	return pData;
}

int main()
{
	char arr[] = "I am a student.";
	cout << arr;
	char* tmp = reverseSentence(arr);
	cout << tmp;
}