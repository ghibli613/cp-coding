#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int m, n, k;
	cin >> m >> n >> k;
	for(int i = 0; i < m; i++)
	{
		string s = "";
		for(int j = 0; j < n; j++)
		{
			char a; cin >> a;
			for(int j1 = 0; j1 < k; j1++)
				s.push_back(a);
		}
		for(int j = 0; j < k; j++) cout << s << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;

	while(t--)	
		solve();
	
	return 0;	
}
