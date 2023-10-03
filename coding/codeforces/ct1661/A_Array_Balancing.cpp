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
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll minimum = 0;
    rep(i, n - 1)
        minimum += min(abs(a[i] - a[i+1]) + abs(b[i] - b[i+1]), abs(a[i] - b[i+1]) + abs(b[i] - a[i+1])) ;

    cout << minimum << nl;
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
