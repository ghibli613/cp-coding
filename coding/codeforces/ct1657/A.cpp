#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

double dist(int x, int y)
{
	return sqrt(x*x + y*y);
}

void solve()
{
	int x, y; cin >> x >> y;
	if(x == 0 && y == 0) cout << 0 << '\n';
	else
	{
		double d = dist(x, y);
		if(floor(d) == d) cout << 1 << '\n';
		else cout << 2 << '\n';
	}
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

