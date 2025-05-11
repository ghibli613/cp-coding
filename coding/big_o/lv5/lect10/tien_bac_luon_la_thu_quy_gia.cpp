#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
const int MOD = 1e9 + 7;

const int N = 2e3 + 1;
int n, sum[N];
int opt[N][N], dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
        opt[i][i] = i;
        for (int j = i + 1; j <= n; j++)
        {
            dp[i][j] = -INF;
        }
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; k++)
            {
                int val = min(dp[i][k] + sum[k] - sum[i - 1], dp[k + 1][j] + sum[j] - sum[k]);
                if (dp[i][j] < val)
                {
                    dp[i][j] = val;
                    opt[i][j] = k;
                }
            }
        }
    }

    cout << dp[1][n];
    return 0;
}