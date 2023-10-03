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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
#define GHIBLI_DEBUG
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef GHIBLI_DEBUG
#define dbg(...) cerr << "\033[31m"<<__func__<<":"<<__LINE__<<" [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__); cerr << "\033[0m" << endl;
#else
#define dbg(...)
#endif

const char nl = '\n';
const double PI = 3.14159265358979323846;

void solve()
{
 	int n, dmp; cin >> n;
	int dp[10] = {0};
	vi a;
	for(int i = 0; i < n; i++)
	{
		cin >> dmp;
		dmp = dmp % 10;
		if(dp[dmp] != 3)
		{
			dp[dmp]++;
			a.push_back(dmp);
		}
	}
	//dbg(a);
 	n = a.size();
	for(int i = 0; i < n - 2; i++)
		for(int j = i + 1; j < n - 1; j++)
			for(int t = j + 1; t < n; t++)
				if((a[i] + a[j] + a[t]) % 10 == 3)
				{
					cout << "YES" << nl;
					return;
				}	

	cout << "NO" << nl;
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

