#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve()
{
	ll coin_1, coin_2; cin >> coin_1 >> coin_2;
	if(coin_1 == 0) cout << 1 << "\n";
	else cout << coin_1 + coin_2*2 + 1 << "\n";	
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

