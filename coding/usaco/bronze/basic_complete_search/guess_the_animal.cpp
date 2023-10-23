#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<vector<string>> a;
    for(int i = 0; i < n; i++)
    {
    	int m; cin >> m;
    	vector<string> tmp;
    	for(int j = 0; j < m; j++) 
    	{
    		string s; cin >> s;
    		tmp.push_back(s);
    	}
    	a.push_back(tmp);
    } 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}