#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	char count[256];

public:
	int findFirstNotRepeatChar(const string& str)
	{
		if (str.length() == 0)
		{
			cout << "input string is null" << endl;
			return -1;
		}

		memset(count, 0, 256);
		for (int i = 0; i < str.length(); i++)
		{
			count[str[i]]++;
		}

		for (int i = 0; i < str.length(); i++)
		{
			if (count[str[i]] == 1)
			{
				return i;
			}
		}

		return -1;
	}
};

int main()
{
	string str = "abvddfadsb";
	Solution solu;
	int idx = solu.findFirstNotRepeatChar(str);
	cout << "the first not repeat char is: ";
	cout << str[idx] << endl;
}