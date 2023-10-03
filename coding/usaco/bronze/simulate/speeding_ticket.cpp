#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n, m, ans = 0; cin >> n >> m;
	queue<pair<int,int>> a, b;
	for(int i = 0; i < n; i++)
	{
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
		a.push(tmp);
	}
	for(int i = 0; i < m; i++)
	{
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
		b.push(tmp);
	}
	while(!a.empty())
	{
		if(a.front().first > b.front().first)
		{
			a.front().first -= b.front().first;
			ckmax(ans, b.front().second - a.front().second);
			b.pop();
		}
		else if(a.front().first == b.front().first)
		{
			ckmax(ans, b.front().second - a.front().second);
			b.pop(); a.pop();
		}
		else
		{
			b.front().first -= a.front().first;
			ckmax(ans, b.front().second - a.front().second);
			a.pop();
		}
	}
	cout << ans;
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
