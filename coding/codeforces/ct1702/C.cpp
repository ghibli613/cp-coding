#include<bits/stdc++.h>
using namespace std;
// #define LOCAL
#ifdef LOCAL
	#include"debug.h"
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

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const char nl = '\n';
const double PI = 3.14159265358979323846;

void solve()
{
	int n, k; cin >> n >> k;
    map<int, pi> u;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(u.find(x) == u.end())
        {
            u[x].first = i;
            u[x].second = i;
        }
        else
        {
            ckmin(u[x].first, i);
            ckmax(u[x].second, i);
        }
    }
    vi a(k), b(k);
    for(int i = 0; i < k; i++) cin >> a[i] >> b[i];
    
    for(int i = 0; i < k; i++)
    {
        if(u.find(a[i]) == u.end() || u.find(b[i]) == u.end()) cout << "NO" << nl;
        else
        {
            if(u[a[i]].first <= u[b[i]].second) cout << "YES" << nl;
            else cout << "NO" << nl;
        }
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
