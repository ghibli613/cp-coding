// time-limit: 1000
// problem-url: https://codeforces.com/problemset/problem/1660/C
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void solve()
{
	string s; cin >> s;
	array<bool,26> prev {false};
	int m = 0;
	int n = s.size();
	for(int i = 0; i < n; i++)
	{
		if(prev[s[i]-97])
		{
			prev.fill(false);
			m = m + 2;
		}
		else prev[s[i]-97] = true;
	}
	cout << n - m << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	while(t--)
	{
		solve();
	}
	
	return 0;	
}
