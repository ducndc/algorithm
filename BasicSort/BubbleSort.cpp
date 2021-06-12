#include <bits/stdc++.h>

using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " " << endl;
	}
}

int main(void)
{
	int arr[] = {11, 55, 33, 99, 22, 55, 77, 88};
	int n = sizeof(arr)/sizeof(arr[0]);

	bubbleSort(arr, n);

	cout << "Sorted array: \n";

	printArray(arr, n);

	return 0;
}