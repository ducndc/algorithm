#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
	while (left <= right)
	{
		int middle = left + (right-1) / 2;

		if (arr[middle] == x)
		{
			return middle;
		}

		if (arr[m] < x)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}

	}

	return -1;
}

int main(void)
{
	int arr[] = {2, 3, 4, 10, 45};
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n-1, x);

	if (result == -1)
	{
		cout << "Element is not present in array";
	}
	else
	{
		cout << "Element is present at index " << result;
	}

	return 0;
}