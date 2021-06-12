#include <bits/stdc++.h>

using namespace std;

int interpolationSearch(int arr[], int n, int x)
{
	int lo = 0;
	int hi = n - 1;

	while (lo <= hi && x >= arr[lo] && x <= arr[hi])
	{
		if (lo == hi)
		{
			if (arr[lo] == x)
			{
				return lo;
			}

			return -1;
		}

		int pos = lo + (x - arr[lo]) * (double)(hi-lo) / (arr[hi] - arr[lo]);

		if (arr[pos] == x)
		{
			return pos;
		}

		if (arr[pos] < x)
		{
			lo = pos + 1;
		}
		else
		{
			hi = pos - 1;
		}
	}

	return -1;
}

int main(void)
{
	int arr[] = {10, 12, 13, 16, 17, 18, 19, 20, 
				21, 22, 23, 24, 25, 26, 27};

	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 18;
	int index = interpolationSearch(arr, n, x);

	if (index != -1)
	{
		cout << "Element found at index \n" << index;
	}
	else
	{
		cout << "Element not found \n";
	}

	return 0;
}