#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
 
void solve()
{
	int n; cin >> n;
	vector<int> a(n+1);
	a[0] = 0;
	int max_1 = 0, max_2 = 0;
	for(int i = 1; i < n+1; i++)
		cin >> a[i];
 
	for(int i = 1; i < n+1; i++)
	{
		if(a[max_1] < a[i])
		{
			max_2 = max_1;
			max_1 = i;
		}
		else if(a[max_2] < a[i]) max_2 = i;
	}
	if(a[max_1] == a[max_2] + 1 || a[max_1] == a[max_2]) cout << "YES\n";
	else cout << "NO\n";
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

