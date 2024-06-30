#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define M(_1, _2, _3, _4, NAME, ...) NAME
#define rep(...) M(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rep4(_, x, n, s) for (int _ = x; (s < 0) ? _ > n : _ < n; _ += s)
#define rep3(_, x, n) rep4(_, x, n, (x < n ? 1 : -1))
#define rep2(_, n) rep3(_, 0, n)
#define rep1(n) rep2(i, n)

using ll = long long;
using ull = unsigned long long;

void solve()
{
	int n; cin >> n;
	vector<pair<string,int>> a(n);
	map<string,int> mymap;
	rep(i, n)
	{
		cin >> a[i].first;
		int prev = 0;
		bool check = false;
		for(int j = i - 1; j > -1; j--)
			if(a[j].first == a[i].first)
			{
				prev = a[j].second;
				check = true;
				break;
			}

		cin >> a[i].second;
		int tmp = a[i].second;
		a[i].second += prev;

		if(!check)
			mymap[a[i].first] = tmp;
		else mymap[a[i].first] += tmp;
	}

	int max = -1e6;
	for(map<string,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		if(it->second > max) max = it->second;

	rep(i, n)
	{
		if(a[i].second >= max && mymap[a[i].first] == max)
		{
			cout << a[i].first << nl;
			break;
		}	
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	// cin >> t;

	rep(t)	
		solve();
	
	return 0;	
}
