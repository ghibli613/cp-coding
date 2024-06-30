#include<bits/stdc++.h>
using namespace std;

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
	string s; cin >> s;
    int ans = 0;
    unordered_set<char> my_set;
    for(int i = 0; i < int(s.size()); i++)
    {
        if(my_set.size() == 3)
        {
            if(my_set.find(s[i]) == my_set.end())
            {
                ans++;
                my_set.clear();
                my_set.insert(s[i]);
            }
        }
        else
        {
            my_set.insert(s[i]);
        }
    }
    if(my_set.empty() == false) ans++;
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
