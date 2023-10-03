#include<bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n, m; cin >> n >> m;
	bool check = false;
	vector<vector<char>> a;
	for(int i = 0; i < n; i++)
	{
		vector<char> tmp(m);
		for(int j = 0; j < m; j++)
		{
			cin >> tmp[j];
			if(tmp[j] == '*')
				check = true;
		}
		if(check) a.push_back(tmp);
	}
	
	for(int i = int(a.size()) - 1; i >= 0; i--)
	{
		for(int j = 0; j < m; j++)
			if(a[i][j] == '*') check = false;
		if(check) a.pop_back();
	}
	check = true;
	int x = 0, y = 0;
	for(int j = 0; j < m; j++)
	{
		for(int i = 0; i < int(a.size()); i++)
			if(a[i][j] == '*') check = false;
		if(check) x++;
	}
	check = true;
	for(int j = m-1; j >= 0; j--)
	{
		for(int i = 0; i < int(a.size()); i++)
			if(a[i][j] == '*') check = false;
		if(check) y++;
	}

	
	for(int i = 0; i < int(a.size()); i++)
	{
		for(int j = x; j < int(a[i].size())-y; j++)
			cout << a[i][j];
		cout << '\n';
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
