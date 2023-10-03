#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
	#include"../debug.h"
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
	int n; cin >> n;
	vi cnt(n);
	vector<vi> a(n);
	for(int i = 0; i < n; i++)
	{
		int t1, t2; cin >> t1 >> t2;
		if(t1 > n || t2 > n) 
		{
			cout << "NO" << nl;
			return;
		}
		cnt[t1-1]++;
		cnt[t2-1]++;
		a[t1-1].push_back(t2-1);
		a[t2-1].push_back(t1-1);
	}	
	for(int i = 0; i < n; i++)
	{
		if(cnt[i] != 2)
		{
			cout << "NO" << nl;
			return;
		}
	}
	set<int> check;
	for(int i = 0; i < n; i++)
	{
		if(check.find(i) == check.end())
		{
			int point = i;
			check.insert(point);
			int count = 0;
			while(check.find(a[point][0]) == check.end() || check.find(a[point][1]) == check.end())
			{
				if(check.find(a[point][0]) == check.end())
				{
					count++;
					point = a[point][0];
					check.insert(point);
				}
				else if(check.find(a[point][1]) == check.end())
				{
					count++;
					point = a[point][1];
					check.insert(point);
				}
			}
			if(count % 2 == 0) 
			{
				cout << "NO" << nl;
				return;
			}
		}
	}	
	cout << "YES" << nl;
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
