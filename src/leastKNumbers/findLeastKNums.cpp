#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

class Solution
{
public:
	typedef multiset<int,greater<int>> IntHeap;

public:
	void FindKLeastNums(const vector<int>& data, IntHeap& LeastNums, unsigned int K)
	{
		LeastNums.clear();

		if (K == 0 || data.size() < K)
		{
			cout << "K == 0 or vector size less K" << endl;
			return;
		}

		auto itor = data.begin();

		for (; itor != data.end(); ++itor)
		{
			if (LeastNums.size() < K)
			{
				LeastNums.insert(*itor);
			}
			else
			{
				auto begItor = LeastNums.begin();
				if (*itor < *(LeastNums.begin()))
				{
					LeastNums.erase(begItor);
					LeastNums.insert(*itor);
				}
			}
		}
	}
};

int main()
{
	int arr[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	vector<int> vec(arr, arr + 8);
	multiset<int,greater<int>> intSet;

	Solution solu;
	solu.FindKLeastNums(vec, intSet, 4);

	for (auto i = intSet.rbegin(); i != intSet.rend();++i)
	{
		cout << *i << endl;
	}

	return 0;
}