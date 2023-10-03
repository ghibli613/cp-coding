#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
void solve()
{
	int n; cin >> n;
	string s; cin >> s;
	int count = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(s[i] == '0' && s[i+1] == '0') count = count + 2;
		else if(s[i] == '0' && s[i+1] == '1' && s[i+2] == '0') count++;
	}
	cout << count << '\n';	
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
