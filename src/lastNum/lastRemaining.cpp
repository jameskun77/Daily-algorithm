//Ô¼Éª·òÎÊÌâ

#include <iostream>
#include <list>

using namespace std;

int LastRemaining(unsigned int n, int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}

	list<int> intList;
	for (int i = 0; i < n;i++)
	{
		intList.push_back(i);
	}

	auto curr = intList.begin();
	while (intList.size()>1)
	{
		for (int i = 1; i < m;i++)
		{
			curr++;
			if (curr == intList.end())
			{
				curr = intList.begin();
			}
		}

		auto next = ++curr;
		if (next == intList.end())
		{
			next = intList.begin();
		}

		--curr;
		intList.erase(curr);
		curr = next;
	}

	return (*curr);
}

int main()
{
	cout << LastRemaining(5, 3);
}