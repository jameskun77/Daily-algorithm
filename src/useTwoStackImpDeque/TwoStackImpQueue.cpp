#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
	void push(int val)
	{
		mInStack.push(val);
	}

	int pop()
	{
		if (mInStack.empty() && mOutStack.empty())
		{
			cout << "queue is empty." << endl;
		}
		else
		{
			if (mOutStack.empty())
			{
				while (!mInStack.empty())
				{
					int valTop = mInStack.top();
					mInStack.pop();
					mOutStack.push(valTop);
				}
			}
		}

		int valTmp = mOutStack.top();
		mOutStack.pop();

		return valTmp;
	}

protected:
	stack<int> mInStack;
	stack<int> mOutStack;
};

int main()
{
	Solution solu;
	solu.push(3);
	solu.push(13);
	solu.push(7);

	cout << "first value is: " << solu.pop() << endl;
}
