#include <iostream>

int search(int arr[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x) 
		{
			return i;
		}
	}

	return -1;
}

int main(void)
{
	int arr[] = { 1, 3, 5, 2, 4, 10, 8, 0, 9};
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);

	int result = search(arr, n, x);

	if (result == -1)
	{
		std::cout << "Element is not present in array";
	}
	else
	{
		std::cout << "Element is present at index " << result;
	}

	return 0;
}