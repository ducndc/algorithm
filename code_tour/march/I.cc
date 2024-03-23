#include <iostream>
#include <vector>
#include <set>

using namespace std;

long long ABS(long long n)
{
	if (n > 0)
		return n;
	else 
		return (-1 * n);
}

int main()
{
	ios::sync_with_stdio(0);
	
	long long Q;
	cin >> Q;
	char t;
	long long ans = 0;
	long long x;
	long long y;
	long long n;
	long long id = 0;
	vector<pair<long long, long long>> XY;

	set<pair<long long, long long>> maxSum;
	set<pair<long long, long long>> minSum;
	set<pair<long long, long long>> maxDiff;
	set<pair<long long, long long>> minDiff;

	while (Q--)
	{
		cin >> t;
		if (t == '+')
		{
			cin >> x >> y;
			x = x ^ ans;
			y = y ^ ans;
			XY.push_back(make_pair(x, y));
			maxSum.insert(make_pair(x + y, id));
			minSum.insert(make_pair(x + y, id));
			maxDiff.insert(make_pair(x - y, id));
			minDiff.insert(make_pair(x - y, id));
			id++;
		}
		else if (t == '-')
		{
			cin >> n;
			n = n ^ ans;
			n--;
			x = XY[n].first;
			y = XY[n].second;
			maxSum.erase(make_pair(x+y, n));
			minSum.erase(make_pair(x+y, n));
			maxDiff.erase(make_pair(x-y, n));
			minDiff.erase(make_pair(x-y, n));
		}
		else if (t == '?')
		{
			cin >> x >> y;
			x = x ^ ans;
			y = y ^ ans;
			auto it1 = maxSum.end();
			auto it2 = maxDiff.end();
			auto it3 = minSum.begin();
			auto it4 = minDiff.begin();
			it1--;
			it2--;
			long long a = (*it2).first - (x - y);
			long long b = (x - y) - (*it4).first;
			long long c = (*it1).first - (x + y);
			long long d = (x + y) - (*it3).first;
			long long max_path = max(max(ABS(a), ABS(b)), max(ABS(c), ABS(d)));
			ans = max_path;
			cout << ans << endl;
		}
	}

	return 0;
}