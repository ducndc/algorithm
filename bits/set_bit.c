#include <stdio.h>

int main()
{
	int number;
	int n;

	printf("Enter an 8 bits interger number: ");
	scanf("%d", &number);

	printf("Enter a bit number (from 0 to 7) to check, whether it is SET or "
			": ");
	scanf("%d", &n);

	if (number & (1 << n))
	{
		printf("Bit number %d is SET in number %d.\n", n, number);
	}
	else
	{
		printf("Bit number %d is not SET in number %d.\n", n, number);
	}

	return 0;
}
