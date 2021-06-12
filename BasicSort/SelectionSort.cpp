#include <bits/stdc++.h>

using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		min_idx = i;

		for (int j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}

			swap(&arr[min_idx], &arr[i]);
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
	int arr[] = {33, 55, 11, 77, 33, 22, 99};
	int n = sizeof(arr)/sizeof(arr[0]);

	selectionSort(arr, n);

	cout << "Sorted array: \n";

	printArray(arr, n);

	return 0;
}