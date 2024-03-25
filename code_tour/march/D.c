#include <stdio.h>

int main()
{
	int q;
	scanf("%d", &q);
	int task[q][2];
	int empty[q];
	int i = 0;
	int number_shirt = 0;
	for (i = 0; i < q; ++i)
	{
		scanf("%d", &task[i][0]);
		if (1 == task[i][0])
		{
			scanf("%d", &task[i][1]);
		}
	}

	for (i = 0; i < q; ++i)
	{
		if (task[i][0] == 1)
		{
			empty[number_shirt] = task[i][1];
			number_shirt += 1;
		}
		else if (task[i][0] == 2)
		{
			if (number_shirt != 0)
				number_shirt -= 1;
		}
		else if (task[i][0] == 3)
		{
			if (number_shirt == 0)
				printf("Empty!\n");
			else
			{
				printf("%d\n", empty[number_shirt-1]);
			}
		}
	}

	return 0;
}