//包含最小值的stack

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
	void push(int val)
	{
		this->dataStack.push(val);

		if (this->minStack.size() == 0 || val < this->minStack.top())
		{
			this->minStack.push(val);
		}
		else
		{
			this->minStack.push(this->minStack.top());
		}
	}

	void pop()
	{
		if (this->dataStack.size() > 0 && this->dataStack.size() > 0)
		{
			this->dataStack.pop();
			this->minStack.pop();
		}
	}

	int top()
	{
		if (this->dataStack.size() > 0)
		{
			return this->dataStack.top();
		}
		else
		{
			cout << "data stack size is zero" << endl;
			return -1;
		}
	}

	int min()
	{
		if (this->minStack.size() > 0)
		{
			return this->minStack.top();
		}
		else
		{
			cout << "min stack size is zero" << endl;
			return -1;
		}
	}


protected:
	stack<int> minStack;
	stack<int> dataStack;
};

int main()
{
	Solution solu;
	solu.push(100);
	solu.push(457);
	solu.push(777);
	solu.push(233);


	cout <<"stack min value: "<< solu.min() << endl;
	cout << "stack top value: " << solu.top() << endl;
}