#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	vector<int> a(n);
	int even = 0, odd = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] % 2 == 0) even += a[i];
		else odd += a[i];
	}

	if(even > odd) cout << "YES\n";
	else cout << "NO\n";
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
