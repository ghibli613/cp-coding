#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve()
{
	ll n, B, x, y;
	cin >> n >> B >> x >> y;
	vector<ll> A(n+1);
	A[0] = 0;
	ll res = 0;
	for(int i = 1; i <= n; i++)
	{
		if(A[i-1] + x > B)
		   A[i] = A[i-1] - y;
		else A[i] = A[i-1] + x;	
		res = res + A[i];
	}
	cout << res << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
	
	return 0;	
}

