#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, c, p; cin >> n >> c >> p;
    vector<vector<string>> a(4);
    for(int i = 0; i < n; i++)
    {
    	string s, t;
    	cin >> s >> t;
    	if(t == "noun") a[0].push_back(s);
    	else if(t == "transitive-verb") a[1].push_back(s);
    	else if(t == "intransitive-verb") a[2].push_back(s);
    	else a[3].push_back(s);
    }
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