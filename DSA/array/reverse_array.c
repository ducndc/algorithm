#include <stdio.h>

#define ARRAY_SIZE 10

#define REVERSE

void print_array(int array[])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void swap_array(int *a, int *b)
{
	int temp_value = *a;
	*a = *b;
	*b = temp_value;
}

void reverse_array(int array[])
{
	int temp_value;

	for (int i = 0; i < (int)(ARRAY_SIZE/2); i++)
	{
		temp_value = array[ARRAY_SIZE-1-i];
		array[ARRAY_SIZE-1-i] = array[i];
		array[i] = temp_value;
	}
}

void rotate_array(int array[], int index)
{
	int temp_index = index;
	int temp_value;
	for (int i = 0; i < temp_index; i++)
	{
		temp_value = array[ARRAY_SIZE-1];
		for (int j = (ARRAY_SIZE-1); j > 0; j--)
		{
			array[j] = array[j-1];
		}
		array[0] = temp_value;
	}
}

int main()
{
	int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int index;
	print_array(array);

#ifdef REVERSE
	reverse_array(array);

	print_array(array);
#endif

	scanf("%d", &index);
	rotate_array(array, index);

	print_array(array);
	return 0;
}
