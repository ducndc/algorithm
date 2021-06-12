int ternarySearch(int arr[], int left, int right, int x)
{
	if (right >= left)
	{
		int middle1 = left + (right - left)/3;
		int middle2 = middle1 + (r-l)/3;

		if (arr[middle1] == x) 
		{
			return middle1;
		}

		if (arr[middle2] == x)
		{
			return middle2;
		}

		if (arr[middle1] > x)
		{
			return ternarySearch(arr, left, middle1-1, x);
		}

		return ternarySearch(arr, middle1+1, middle2-1, x);
	}

	return -1;
}