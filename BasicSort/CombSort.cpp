#include <bits/stdc++.h>

using namespace std;

/*
 * To find gap between elements
 */
int getNextGap(int gap)
{
	/*
	 * Shirk gap by Shrink factor
	 */
	gap = (gap*10) / 13;

	if (gap < 1)
	{
		return 1;
	}

	return gap;
}

/*
 * 
 */
void combSort(int arr[], int n)
{
	bool swapped = true;
	int gap = n;

    /*
     * Keep running while gap is more than 1 and last
     * iteration caused s swap
     */
	while (gap != 1 || swapped == true)
	{
		gap = getNextGap(gap);

		swapped = false;

		for (int i = 0; i < n-gap; i++)
		{
			if (arr[i] > a[i+gap])
			{
				swap(a[i], a[i+gap]);
				swapped = true;
			}
		}
	}

}

int main()
{
    int a[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(a)/sizeof(a[0]);
 
    combSort(a, n);
 
    printf("Sorted array: \n");
    for (int i=0; i<n; i++)
        printf("%d ", a[i]);
 
    return 0;
}