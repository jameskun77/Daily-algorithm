//fibonacci
// f(n) = f(n-1) + f(n-2);  n>1

#include <iostream>

using namespace std;

long long Fibonacci(unsigned n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
	{
		return result[n];
	}

	long long fibNMinusOne = 1;
	long long fibNMinusTwo = 0;
	long long fibN = 0;

	for (int i = 2; i <= n; i++)
	{
		fibN = fibNMinusOne + fibNMinusTwo;

		fibNMinusTwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}

	return fibN;
}

int main()
{
	cout <<"sizeof long "<< sizeof(long) << endl;
	cout << "sizeof long long " << sizeof(long long) << endl;

	cout << Fibonacci(10) << endl;
}