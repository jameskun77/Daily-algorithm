#include <iostream>

using namespace std;

void swap(int& a, int& b);

//bubble
void bubbleSort(int arr[], int len)
{
	if (NULL == arr)
	{
		cout << "input is null" << endl;
		return;
	}

	for (int i = 0; i < len; ++i)
	{
		for (int j = 1; j < len - i; ++j)
		{
			if (arr[j-1] > arr[j])
			{
				swap(arr[j - 1], arr[j]);
			}
		}
	}
}

//inset
void insertSort(int arr[], int len)
{
	if (NULL == arr)
	{
		cout << "input is NULL" << endl;
		return;
	}

	for (int i = 1; i < len; ++i)
	{
		for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1];--j)
		{
			swap(arr[j], arr[j+1]);
		}
	}
}

//shell
void shellSort(int arr[], int len)
{
	if (NULL == arr)
	{
		cout << "input is NULL" << endl;
		return;
	}

	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < len; ++i)
		{
			for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
			{
				swap(arr[j], arr[j + gap]);
			}
		}
	}
}

//select
void selectSort(int* arr, int len)
{
	if (NULL == arr)
	{
		cout << "input is NULL" << endl;
		return;
	}

	int minIndex = 0;
	for (int i = 0; i < len; ++i)
	{
		minIndex = i;
		for (int j = i + 1; j < len;++j)
		{
			int currVal = arr[j];
			int minVal = arr[minIndex];
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		swap(arr[i], arr[minIndex]);
	}
}

//merger
void mergerArr(int a[], int first, int mid, int end, int tmp[])
{
	int i = first;
	int j = mid + 1;

	int m = mid;
	int n = end;

	int count = 0;

	while (i <= m && j <= n)
	{
		if (a[i] < a[j])
			tmp[count++] = a[i++];
		else
			tmp[count++] = a[j++];
	}

	while (i <= m)
	{
		tmp[count++] = a[i++];
	}

	while (j <= n)
	{
		tmp[count++] = a[j++];
	}

	for (int i = 0; i < count; i++)
	{
		a[first + i] = tmp[i];
	}
}

void mergerSortCore(int arr[], int l, int r,int tmp[])
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		mergerSortCore(arr, l, mid, tmp);
		mergerSortCore(arr, mid + 1, r, tmp);
		mergerArr(arr, l, mid, r, tmp);
	}
}

void mergerSort(int arr[], int len)
{
	int *p = new int[len];
	if (p == NULL)
	{
		cout << "new memory fail" << endl;
		return;
	}

	mergerSortCore(arr, 0, len - 1, p);
	delete[] p;
}

//fast
void fastSort(int arr[], int l,int r)
{
	if (l < r)
	{
		int i = l, j = r, base = arr[l];
		
		while (i < j)
		{
			while (i < j && arr[j] > base)
				--j;

			if (i < j)
			{
				swap(arr[j], arr[i++]);
			}

			while (i < j && arr[i] < base)
				++i;

			if (i < j)
			{
				swap(arr[i], arr[j--]);
			}
		}

		arr[i] = base;
		fastSort(arr, l, i - 1);
		fastSort(arr, i + 1, r);
	}
}

void swap(int& a, int& b)
{
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
}

int main()
{
	int a[5] = { 15, 33, 2, 7, 99 };
	//bubbleSort(a, 5);
	//fastSort(a, 0,4);
	//insertSort(a, 5);
	//shellSort(a, 5);
	//selectSort(a, 5);
	mergerSort(a, 5);
	
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << endl;
	}
}