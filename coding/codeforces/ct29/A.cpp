#include<bits/stdc++.h>
using namespace std;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	map<int, int> my_map;
	for(int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		my_map[a] = b;
	}

	for(map<int, int>::iterator it = my_map.begin(); it != my_map.end(); it++)
	{
		int a = it->first + it->second;
		if(my_map.find(a) != my_map.end() && my_map[a] + a == it->first)
		{
			cout << "YES";
			return;
		}
	}
	cout << "NO";
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
