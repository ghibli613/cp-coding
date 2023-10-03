#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	ll x, y;
	cin >> x >> y;

	ll ans = 0;
	ll by = 1;
	ll dir = 1;
	while(true) 
	{
		if((dir==1 && x<=y && y<=x+by) || (dir==-1 && x-by<=y && y<=x)) 
		{
			ans += abs(y-x);
			cout << ans << endl;
			break;
		} 
		else 
		{
			ans += by*2;
			by *= 2;
			dir *= -1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;

	while(t--)	
		solve();
	
	return 0;	
}
