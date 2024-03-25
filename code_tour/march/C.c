#include <stdio.h>

int main()
{
	int test_case;
	scanf("%d", &test_case);
	int i;
	int M[test_case];
	int j;
	int x[test_case][2];
	int y[test_case][2];
	int x_[test_case][100];
	int y_[test_case][100];

	for (i = 0; i < test_case; ++i)
	{
		scanf("%d %d %d %d", &x[i][0], &y[i][0], &x[i][1], &y[i][1]);
		scanf("%d", &M[i]);


		for (j = 0; j < M[i]; ++j)
		{
			scanf("%d %d", &x_[i][j], &y_[i][j]);
		}

	}

	for (i = 0; i < test_case; ++i)
	{
		printf("Case %d:\n", i+1);
		for (j = 0; j < M[i]; ++j)
		{
			if (x[i][0] < x_[i][j] && x_[i][j] < x[i][1] && 
				y[i][0] < y_[i][j] && y_[i][j] < y[i][1])
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
		}
	}
	return 0;
}