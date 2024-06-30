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
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;

	rep(t)	
		solve();
	
	return 0;	
}
