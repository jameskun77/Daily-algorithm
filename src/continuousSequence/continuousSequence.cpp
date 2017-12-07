//输入一个正数s，打印所有和为s的连续正数序列（至少含两个数字）
//s=15
//cout:1 2 3 4 5, 4 5 6, 7 8.

#include <iostream>

using namespace std;

void printContinuousSequence(int small, int big)
{
	for (int i = small; i <= big;i++)
	{
		cout << i << " ";
	}

	cout << endl;
}

void findContinuousSequence(int sum)
{
	if (sum < 3)
		return;
	
	int small = 1;
	int big = 2;
	int mid = (sum + 1) / 2;
	int curSum = big + small;

	while (small < mid)
	{
		if (curSum == sum)
		{
			printContinuousSequence(small, big);
		}

		while (curSum > sum && small < mid)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
			{
				printContinuousSequence(small, big);
				break;
			}
		}

		big++;
		curSum += big;
	}
}

int main()
{
	findContinuousSequence(15);
	
	return 0;
}