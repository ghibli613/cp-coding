#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
	int n; cin >> n;
	vector<int> a(n); vector<string> shuffle(n), tmp(n);
	for(int i = 0; i < n; i++)
	{	
		cin >> a[i];
		a[i]--;
	}
	for(int i = 0; i < n; i++)
		cin >> shuffle[i];
	for(int j = 0; j < 3; j++)
	{
		for(int i = 0; i < n; i++)
			tmp[i] = shuffle[a[i]];
	   shuffle = tmp;	
	}
			
	for(int i = 0; i < n; i++)
		cout << shuffle[i] << "\n";
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
