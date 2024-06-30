#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	vector<int> c(n);
	vector<ll> sum(n);
	for(int i = 0; i < n; i++) cin >> c[i];
	sort(c.begin(), c.end());

	if(c[0] != 1)
	{
		cout << "NO\n";
		return;
	}
	sum[0] = c[0];

	for(int i = 1; i < n; i++)
	{
		if(c[i] > sum[i-1])
		{
			cout << "NO\n";
			return;
		}
		else
		{
			sum[i] = c[i] + sum[i-1];
		}

	}
	cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;

	while(t--)	
		solve();
	
	return 0;	
}
