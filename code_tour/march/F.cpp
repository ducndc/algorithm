#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N = 2e3+5;

	long long n;
	long long a[N];
	long long t;
	long long k;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> n >> k;
		for (int j = 0; j < n; ++j)
		{
			cin >> a[j];
		}

		if (k >= 3)
		{
			cout << 0 << endl;
			continue;
		}

		sort(a, a + n);
		long long min_array = a[0];

		for (int j = 0; j < n; ++j)
		{
			for (int g = 0; g < j; ++g)
			{
				long long tmp = a[j] - a[g];
				min_array = min(tmp, min_array);
				if (k == 2)
				{
					int y = lower_bound(a, a+n, tmp) - a;
					min_array = min({min_array, a[y] - tmp, tmp - a[y-1]});
				}
			}
		}
		cout << min_array << endl;
	}
}