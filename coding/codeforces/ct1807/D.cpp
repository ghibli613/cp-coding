#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n, q; cin >> n >> q;
	vector<ll> a(n), sum(n);
	cin >> a[0]; sum[0] = a[0];
	for(int i = 1; i < n; i++)
	{
		cin >> a[i];
		sum[i] = a[i] + sum[i-1];
	}
	
	for(int i = 0; i < q; i++)
	{
		int l, r; ll k; cin >> l >> r >> k;
		ll ans;
		if(l - 1 > 0) ans = sum[n-1] - sum[r-1] + sum[l-2] + (r - l + 1) * k;
		else ans = sum[n-1] - sum[r-1] + (r - l + 1) * k;
		if(ans % 2 == 0) cout << "NO\n";
		else cout << "YES\n";
	}
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
