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
	int n;
    cin >> n;
    
    map<int, vi> p;
    
    vi x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        p[x[i]].push_back(i);
    }
    
    int a = x[0], l = 0, r = 1, ans = 1;
    
    for (map<int, vi>::iterator tmp = p.begin(); tmp != p.end(); tmp++) {
        int min = 0, k = tmp->second[0];
        for (int j = 0; j < int(tmp->second.size()); j++) {
            int i = tmp->second[j];
            int cur = j - (i - j);
            if (ckmin(min, cur))
                k = i;
            int res = cur + 1 - min;
            if (ckmax(ans,res)) {
                a = tmp->first;
                l = k;
                r = i + 1;
            }
        }
    }
    
    cout << a << " " << l + 1 << " " << r << nl;
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
