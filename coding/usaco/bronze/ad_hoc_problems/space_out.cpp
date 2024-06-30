#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    int rows_alternate = 0, cols_alternate = 0;
    for(int i = 0; i < n; i++)
    {
        int sum[2] = {0 , 0};
        for(int j = 0; j < n; j++)
            sum[j % 2] += grid[i][j];

        rows_alternate += max(sum[0], sum[1]);
    }
    for(int i = 0; i < n; i++)
    {
        int sum[2] = {0 , 0};
        for(int j = 0; j < n; j++)
            sum[j % 2] += grid[j][i];
        cols_alternate += max(sum[0], sum[1]);
    }

    cout << max(rows_alternate, cols_alternate);
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