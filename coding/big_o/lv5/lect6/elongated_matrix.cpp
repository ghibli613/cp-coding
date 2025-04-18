#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    vector<vector<int>> w1(n, vector<int>(n, 0));
    vector<vector<int>> w2(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            w1[i][j] = w2[i][j] = INF;
            for(int k = 0; k < m; k++)
            {
                w1[i][j] = min(w1[i][j], abs(a[i][k] - a[j][k]));
                if(k < m - 1)
                    w2[i][j] = min(w2[i][j], abs(a[j][k] - a[i][k + 1]));
            }
        }

    int ans = 0;
    for(int start = 0; start < n; start++)
    {
        vector<vector<int>> dp(1 << n, vector<int>(n, 0));
        dp[1 << start][start] = INF;

        for(int mask = 0; mask < (1 << n); mask++)
            for(int i = 0; i < n; i++)
                if(mask >> i & 1)
                    for(int j = 0; j < n; j++)
                        if((mask >> j & 1) && i != j)
                            dp[mask][i] = max(dp[mask][i], min(w1[j][i], dp[mask ^ (1 << i)][j]));

        for(int finish = 0; finish < n; finish++)
            ans = max(ans, min(w2[start][finish], dp[(1 << n) - 1][finish]));
    }

    cout << ans;
}