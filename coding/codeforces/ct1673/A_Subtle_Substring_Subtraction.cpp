#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const char nl = '\n';
const double PI = 3.14159265358979323846;

void solve()
{
	string s; cin >> s;
    int n = sz(s);
    if(n % 2 == 0)
    {
        cout << "Alice ";
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum = sum + s[i] - 96;
        }
        cout << sum << nl;
    }
    else
    {
        if(n == 1)
        {
            ll res = s[0] - 96;
            cout << "Bob " << res << nl;
        }
        else
        {
            if(s[0] > s[n-1])
            {
                ll res = 0;
                for(int i = 0; i < n -1; i++)
                    res = res + s[i] - 96;

                ll res1 = s[n-1] - 96;
                if(res < res1) 
                    cout << "Bob " << res1 - res << nl;
                else cout << "Alice " << res - res1 << nl;
            }
            else
            {
                ll res = 0;
                for(int i = 1; i < n; i++)
                    res = res + s[i] - 96;

                ll res1 = s[0] - 96;
                if(res < res1) 
                    cout << "Bob " << res1 - res << nl;
                else cout << "Alice " << res - res1 << nl;
            }
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
