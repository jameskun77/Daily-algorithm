#include <iostream>

using namespace std;

int numberof1_solutuion1(int val)
{
	int count = 0;
	unsigned int flag = 1;

	while (flag)
	{
		if (flag & val)
		{
			count++;
		}
		flag = flag << 1;
	}

	return count;
}

int numberof1_solutuion2(int val)
{
	int count = 0;
	
	while (val)
	{
		count++;
		val = val & (val - 1);
	}

	return count;
}

int main()
{
	cout << numberof1_solutuion1(5) << endl;
	cout << numberof1_solutuion2(5) << endl;
}