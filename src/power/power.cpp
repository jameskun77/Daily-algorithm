//求数值的整数次方

#include <iostream>

using namespace std;

bool equal(double a, double b)
{
	if ((a - b > 0.0000001) && (a - b < -0.0000001))
		return true;
	else
		return false;
}

double powerCore(double base, unsigned int exponent)
{
	double result = 1.0f;
	for (int i = 1; i <= exponent;i++)
	{
		result *= base;
	}

	return result;
}

double power(double base, int exponent)
{
	if (equal(base,0.0) && exponent < 0)
	{
		cout << "input invalided" << endl;
		return -1;
	}

	double result = 0.0;
	if (exponent < 0)
	{
		result = 1.0 / powerCore(base, -exponent);
	}
	else
	{
		result = powerCore(base, exponent);
	}

	return result;
}

int main()
{
	cout << power(10, -2) << endl;
}