#include <iostream>
#include <stack>
#include <queue>

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

class Stack
{
public:

	void push(int x)
	{
		if (!q1.empty())
		{
			q2.push(x);
			while (!q1.empty())
			{
				q2.push(q1.front());
				q1.pop();
			}
		}
		else
		{
			q1.push(x);
			while (!q2.empty())
			{
				q1.push(q2.front());
				q2.pop();
			}
		}
	}

	void pop()
	{
		if (q1.empty() && q2.empty())
		{
			throw new exception("stack is empty");
		}
		else if (!q1.empty())
			q1.pop();
		else
			q2.pop();
	}

	int top()
	{
		if (!q1.empty())
		{
			return q1.front();
		}
		else
		{
			return q2.front();
		}
	}

	bool empty()
	{
		return (q1.empty() && q2.empty());
	}

private:
	queue<int> q1, q2;
};

int main()
{
	Solution solu;
	solu.push(3);
	solu.push(13);
	solu.push(7);

	cout << "first value is: " << solu.pop() << endl;

	Stack stk;
	stk.push(1);
	stk.push(2);
	stk.pop();
	stk.push(3);
	cout << stk.top() << endl;
	stk.push(4);
	cout << stk.top() << endl;
}
