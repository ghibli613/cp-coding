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

int pow_2(int k)
{
	int res = 1;
	for(int i = 0; i < k; i++)
		res *= 2;

	return res;
}

void solve()
{
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	rep(i, n)
	{
		int min_ope = 15;
		for(int j = 0; j <= 15; j++)
			for(int k = 0; k <= 15; k++)
			{
				if(((a[i] + k) * pow_2(j)) % 32768 == 0)
					min_ope = min(min_ope, k+j);
			}

		cout << min_ope << " ";
	}

	cout << nl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	//cin >> t;

	rep(t)	
		solve();
	
	return 0;	
}