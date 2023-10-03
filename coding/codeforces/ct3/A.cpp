#include<bits/stdc++.h>
using namespace std;

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
	string s, t; cin >> s >> t;
    int ans = 0;
    vector<string> path;
    while(s[0] > t[0] && s[1] > t[1])
    {
        s[0]--; s[1]--;
        path.push_back("LD");
        ans++;
    }
    while(s[0] < t[0] && s[1] > t[1])
    {
        s[0]++; s[1]--;
        path.push_back("RD");
        ans++;
    }
    while(s[0] > t[0] && s[1] < t[1])
    {
        s[0]--; s[1]++;
        path.push_back("LU");
        ans++;
    }
    while(s[0] < t[0] && s[1] < t[1])
    {
        s[0]++; s[1]++;
        path.push_back("RU");
        ans++;
    }
    while(s[0] > t[0])
    {
        s[0]--;
        path.push_back("L");
        ans++;
    }
    while(s[0] < t[0])
    {
        s[0]++;
        path.push_back("R");
        ans++;
    }
    while(s[1] < t[1])
    {
        s[1]++;
        path.push_back("U");
        ans++;
    }
    while(s[1] > t[1])
    {
        s[1]--;
        path.push_back("D");
        ans++;
    }
    cout << ans << nl;
    ll n = path.size();
    for(int i = 0; i < n; i++) cout << path[i] << nl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	// cin >> t;

	while(t--)	
		solve();
	
	return 0;	
}