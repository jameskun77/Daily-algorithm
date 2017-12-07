#include <iostream>

using namespace std;

void PrintMatrixInCircle(int** numbers, int cols, int rows, int start)
{
	int endX = cols - 1 - start;
	int endY = rows - 1 - start;

	//left -> right
	for (int i = 0; i <= endX;i++)
	{
		int num = numbers[start][i];
		cout << num << " ";
	}

	if (start < endY)
	{
		for (int i = start + 1; i <= endY;i++)
		{
			int num = numbers[i][endY];
			cout << num << " ";
		}
	}

	if (start < endY && start < endX)
	{
		for (int i = endX - 1; i >= start;i--)
		{
			int num = numbers[endY][i];
			cout << num << " ";
		}
	}

	if (start < endX && start < endY -1)
	{
		for (int i = endY - 1; i >= start;i--)
		{
			int num = numbers[i][start];
			cout << num << " ";
		}
	}
}

void printMatrix(int** matrix, int cols, int rows)
{
	if (NULL == matrix || cols <= 0 || rows == 0)
		return;

	int start = 0;

	while (cols > 2*start && rows > 2*start)
	{
		PrintMatrixInCircle(matrix, cols, rows, start);
		start++;
	}
}

int main()
{
	int numbers[5][5] = {
			{ 1, 2, 3, 4, 5 },
			{ 16, 17, 18, 19, 6 },
			{ 15, 24, 25, 20, 7 },
			{ 14, 23, 22, 21, 8 },
			{ 13, 12, 11, 10, 9 },};

	int **pp1 = new int*[4];
	for (int i = 0; i <= 4; i++)
	{
		pp1[i] = numbers[i];
	}
	printMatrix(pp1, 5, 5);
	cout << endl;
}