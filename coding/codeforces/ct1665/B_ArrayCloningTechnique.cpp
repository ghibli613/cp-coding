// time-limit: 1000
// problem-url: https://codeforces.com/contest/1665/problem/B
#include<bits/stdc++.h>
using namespace std;

#define nl '\n'
#define M(_1, _2, _3, _4, NAME, ...) NAME
#define rep(...) \
	M(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rep4(_, x, n, s) \
  	for (int _ = x; (s < 0) ? _ > n : _ < n; _ += s)
#define rep3(_, x, n) rep4(_, x, n, (x < n ? 1 : -1))
#define rep2(_, n) rep3(_, 0, n)
#define rep1(n) rep2(i, n)

using ll = long long;
using ull = unsigned long long;

void solve()
{
	int n; cin >> n;
	vector<int> a(n);
	map<int,int> mymap;
	int max = 0, index_max = -1;
	rep(i, n)
	{
		cin >> a[i];
		if(mymap.find(a[i]) == mymap.end())
			mymap[a[i]] = 1;
		else mymap[a[i]]++;

		if(mymap[a[i]] > max)
		{
			max = mymap[a[i]];
			index_max = i;
		}
	}
	
	ll clone = 0, swap = 0;
	ll tmp =mymap[a[index_max]];
	while(true)
	{
		if(tmp >= n)
		{
			swap -= (tmp - n);
			break;
		}
		clone++;
		swap += tmp;
		tmp *= 2;
	}
	cout << clone + swap << nl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;

	rep(t)	
		solve();
	
	return 0;	
}
