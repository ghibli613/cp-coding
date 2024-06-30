#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int factorial(int n)
{
 	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

void solve()
{
	int n; cin >> n;
	if(n % 2 == 1) cout << "0\n";
	else
	{
		ll res = 1;
		for(int i = 1; i <= n/2; i++)
			res = (res*i) % 998244353;
		res = (res * res) % 998244353;
		cout << res << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	while(t--)
	{
		solve();
	}
	
	return 0;	
}

