#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>>neighbors(n);
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        neighbors[b - 1].push_back(a - 1);
        neighbors[a - 1].push_back(b - 1);
    } 

    vector<int>colors(n, 0);
    
    for(int i = 0; i < n; i++)
    {
        set<int> all_colors;
        for(int j = 0; j < (int)neighbors[i].size(); j++)
            all_colors.insert(colors[neighbors[i][j]]);

        for(int j = 1; j < 5; j++)
            if(all_colors.count(j) == 0)
            {
                colors[i] = j;
                break;
            }
    }

    for(int i = 0; i < n; i++)
        if(colors[i] == 0) cout << 1;
        else cout << colors[i];
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