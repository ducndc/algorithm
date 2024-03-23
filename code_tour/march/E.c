#include <stdio.h>
#include <stdlib.h>

int main()
{
	int T;
	scanf("%d", &T);
	int num_a[T];
	int num_b[T];
	int *array_a[T];
	int *array_b[T];
	int i = 0;
	int j = 0;

	for (i = 0; i < T; ++i)
	{
		scanf("%d", &num_a[i]);
		array_a[i] = (int *)malloc((num_a[i]) * sizeof(int));

		for (j = 0; j < (num_a[i]); ++j)
		{
			scanf("%d", array_a[i] + j);
		}

		scanf("%d", &num_b[i]);
		array_b[i] = (int *)malloc(num_b[i] * sizeof(int));

		for (j = 0; j < num_b[i]; ++j)
		{
			scanf("%d", array_b[i] + j);
		}
	}

	for (i = 0; i < T; ++i)
	{
		int X = 0;
		for (j = 0; j < num_b[i]; ++j)
		{
			if (*(array_b[i] + j) > 0)
				X += 1;
		}
		
		int num_ab = num_a[i] + X;
		int *AB = (int *)malloc(num_ab * sizeof(int));
		int index = num_a[i];

		for (j = 0; j < num_a[i]; ++j)
		{
			AB[j] = *(array_a[i] + j);
		}
		for (j = 0; j < num_b[i]; ++j)
		{
			if (*(array_b[i] + j) > 0) {
				AB[index] = *(array_b[i] + j);
				index += 1;
			}
		}

		int max_first;
		int max_end;
		int max1 = -2147483648;
		int max2 = 0;
		for (j = 0; j < num_ab; ++j)
		{
			max2 = max2 + AB[j];
			if (max1 < max2)
				max1 = max2;
			if (max2 < 0)
				max2 = 0;
		}
		max_first = max1;

		max1 = -2147483648;
		max2 = 0;
		index = 0;
		for (j = num_b[i] - 1; j >= 0; --j)
		{
			if (*(array_b[i] + j) > 0) {
				AB[index] = *(array_b[i] + j);
				index += 1;
			}
		}
		for (j = index; j < num_ab; ++j)
		{
			AB[j] = *(array_a[i] + j - X);
		}

		for (j = 0; j < num_ab; ++j)
		{
			max2 = max2 + AB[j];
			if (max1 < max2)
				max1 = max2;
			if (max2 < 0)
				max2 = 0;
		}

		max_end = max1;

		if (max_first > max_end)
			printf("%d\n", max_first);
		else
			printf("%d\n", max_end);

		free(AB);
	}

	for (i = 0; i < T; ++i)
	{
		free(array_a[i]);
		free(array_b[i]);
	}
}