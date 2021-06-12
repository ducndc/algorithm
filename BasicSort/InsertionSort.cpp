/*
 *To sort an array of size n in ascending order: 
1: Iterate from arr[1] to arr[n] over the array. 
2: Compare the current element (key) to its predecessor. 
3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.
 */
#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n)
{
	int i;
	int key;
	int j;

	fot (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = i - 1;
		}

		arr[j+1] = key;
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " " << endl;
	}
}

int main(void)
{
	int arr[] = { 11, 44, 22, 33, 66};
	int n = sizeof(arr)/sizeof(arr[0]);

	insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}