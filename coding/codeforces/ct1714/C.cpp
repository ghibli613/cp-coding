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
	int s; cin >> s;
    if(s <= 9) cout << s << nl;
	else
	{
		vector<int> a;
		for(int i = 9; i >= 1; i--)
		{
			if(s < i)
			{
				if(s != 0)a.push_back(s);
				break;
			}
			s -= i;
			a.push_back(i);
		}
		for(int i = int(a.size()) - 1; i >= 0; i--)
			cout << a[i];
		cout << nl;
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