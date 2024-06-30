#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"../../debug.h"
#else
	#define dbg(...)
#endif

typedef long long ll;

typedef pair<int,int> pi;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pd> vpd;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const char nl = '\n';
const double PI = 3.14159265358979323846;

void solve()
{
	map<int, int> a;
	int n; cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int tmp; cin >> tmp;
		if(a.find(tmp) != a.end())
		{
			ckmax(ans, a[tmp] + 1);
			a[tmp] = i;
		}
		else
			a[tmp] = i;
	}
	cout << ans << nl;
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