#include <stdio.h>

int main()
{
	int n; // so luong truy van
	int b; // hang doi
	scanf("%d %d", &n, &b);

	long long int t[n]; // thoi diem truy van den
	long long int d[n]; // thoi gian xu ly truy van

	int i;
	int j = 0;
	int size_q = 0;
	long long int result_time = 0;
	long long int process_time[b + 1];

	for (j = 0; j < (b + 1); ++j)
	{
		process_time[j] = 0;
	}

	for (i = 0; i < n; ++i)
	{
		scanf("%lld %lld", &t[i], &d[i]);
	}

	result_time = t[0] + d[0];
	size_q = 0;
	process_time[0] =  result_time;
	printf("%lld ", result_time);

	for (i = 1; i < n; ++i)
	{
		if ((result_time) <= t[i])
		{
			result_time = t[i] + d[i];
			printf("%lld\n", result_time);
			size_q = 0;
			for (j = 0; j < (b + 1); ++j)
			{
				process_time[j] = 0;
			}
			process_time[0] = result_time;
		}
		else
		{
			if (t[i] < process_time[0] && size_q == b)
			{
				printf("-1 ");
				continue;
			}

			for (j = 0; j < (b + 1); ++j)
			{
				if (process_time[j] != 0 &&
					process_time[j] <= t[i])
				{
					process_time[j] = process_time[j+1];
					if (size_q > 0)
						size_q -= 1;
				}

				if (process_time[j] == 0 || process_time[j] > t[i]);
					break;
			}

			for (j = size_q + 1; j < (b+1); ++j)
			{
				process_time[j] = 0;
			}

			if (size_q == b)
			{
				printf("-1 ");
				continue;
			}
			else
			{
				size_q += 1;
				result_time += d[i]; 
				printf("%lld ", result_time);
				process_time[size_q] = result_time;
			}
		}
	}

	return 0;
}