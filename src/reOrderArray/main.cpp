#include <iostream>
#include <vector>

using namespace std;

void reOrderArray(vector<int>& arr)
{
	if (arr.size() <= 1)
	{
		return;
	}

	auto itorBegin = arr.begin();
	auto itorEnd = arr.end() - 1;

	while (itorBegin != itorEnd)
	{
		while ((itorBegin < itorEnd) && (*itorBegin & 0x01) == 1)
		{
			itorBegin++;
		}

		while ((itorBegin < itorEnd) && (*itorEnd & 0x01) == 0) 
		{
			itorEnd--;
		}

		if (itorBegin < itorEnd)
		{
			swap(*itorBegin, *itorEnd);
		}
	}
}

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> intVec(array, array + 7);
	reOrderArray(intVec);

	auto beginItor = intVec.begin();
	for (; beginItor != intVec.end(); ++beginItor)
	{
		cout << *beginItor << endl;
	}

	return 0;
}