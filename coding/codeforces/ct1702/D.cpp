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
	string s; cin >> s;
    int p; cin >> p;
    int n = int(s.size());
    map<char, vi> my_map;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += s[i] - 96;
        my_map[s[i]].push_back(i);
    }
    
    while(sum > p)
    {
        auto it = my_map.end();
        it--;
        char dmp = it->first;
        int a = my_map[dmp].back();
        my_map[dmp].pop_back();
        sum -= dmp - 96;
        s[a] = 'A';
        if(my_map[dmp].empty() == true) my_map.erase(dmp);
    }
    for(int i = 0; i < n; i++)
        if(s[i] != 'A') cout << s[i];

    cout << nl;
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
