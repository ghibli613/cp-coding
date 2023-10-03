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
	int n, H, M; cin >> n >> H >> M;
	int ans = 1e9;
	for(int i = 0; i < n; i++)
	{
		int tmpH = H;
		int tmp1, tmp2; cin >> tmp1 >> tmp2;
		if(tmp1 < H || (tmp1 == H && tmp2 < M)) tmp1 += 24;
		if(tmp2 < M)
		{
			tmp2 += 60;
			tmpH++;
		}
		int anstmp = (tmp1-tmpH)*60 + tmp2 - M;
		ckmin(ans, anstmp);
	}
	cout << ans / 60 << " " << ans %60 << nl;
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