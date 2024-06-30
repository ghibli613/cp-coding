#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> piles(n * m);
    for(int i = 0; i < n * m; i++) cin >> piles[i];
    int init_x, init_y; cin >> init_x >> init_y;
    int init_value = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(i == init_x - 1 && j == init_y - 1) init_value = piles[i * m + j];
        }

    sort(piles.begin(), piles.end());
    vector<int> ans; ans.push_back(init_value);
    for(int i = 0; i < n * m; i++)
    {
        if(piles[i] > ans[int(ans.size()) - 1]) ans.push_back(piles[i]);
    }

    cout << (int)ans.size() - 1;
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