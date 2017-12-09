//输入一个字符串，把空格用%20替代

#include <iostream>

using namespace std;

void replaceSpace(char* pChar, int len)
{
	int count = 0;
	for (int i = 0; i < len; ++i)
	{
		if (pChar[i] == ' ')
			++count;
	}

	int newLen = len + count * 2;

	pChar[newLen] = '\0';

	int behand = len - 1;
	int end = newLen - 1;
	for (; behand >= 0 && end >= 0;)
	{
		if (pChar[behand] == ' ')
		{
			pChar[end--] = '0';
			pChar[end--] = '2';
			pChar[end--] = '%';
			behand--;
		}
		else
		{
			pChar[end--] = pChar[behand--];
		}
	}

}

int main()
{
	char arr[20] = "a b c d";
	replaceSpace(arr, 7);
	cout << arr << endl;
}