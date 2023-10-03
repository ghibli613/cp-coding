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

ll pow_2(int a)
{
    ll res = 1;
    for(int i = 0; i < a; i++)
    {
        res = res * 2;
    }
    return res;
}

void solve()
{
	string s, t; cin >> s >> t;
    bool check = false;
    for(int i = 0; i < (int)t.size(); i++)
    {
        if(t[i] == 'a') check = true;
    }
    if(t == "a")
    {
        cout << 1 << nl;
        return;
    }
    else if(!check)
    {
        cout << pow_2((int)s.size()) << nl;
        return;
    }
    else
    {
        cout << -1 << nl;
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
