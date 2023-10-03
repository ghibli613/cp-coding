#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	map<char, int> my_map;
	string s; cin >> s;
	for(int i = 0; i < n; i++)
	{
		char dmp; dmp = s[i];
		if(my_map.find(dmp) == my_map.end())
			my_map[dmp] = i;
		else if(my_map[dmp] % 2 != i % 2) 
		{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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
