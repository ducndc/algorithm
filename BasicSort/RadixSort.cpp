#include <iostream>

using namespace std;

int getMax(int arr[], int size)
{
	int max = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

void countSort(int arr[], int n, int exp)
{
	int output[n];
	int i;
	int count[10] = {0};

	for (i = 0; i < n; i++)
	{
		count[(arr[i]/exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i-1];
	}

	for (i = n-1; i >= 0; i--)
	{
		output[count[(arr[i]/exp % 10)] - 1] = arr[i];
		count[(arr[i]/exp) % 10]--;
	}

	for (i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}
}

void radixSort(int arr[], int size)
{
	int m = getMax(arr, size);

	for (int exp = 1; m/exp > 0; exp *= 10)
	{
		countSort(arr, size, exp);
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main(void)
{
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
	int n = sizeof(arr)/sizeof(arr[0]);

	radixSort(arr, n);

	return 0;
}