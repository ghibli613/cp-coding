#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
const int N = 22;

int n;
int a[N][N];
int dp[1 << N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    dp[0] = 1;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        int i = __builtin_popcount(mask);
        for (int w = 0; w < n; w++)
        {
            if (!(mask & (1 << w)) && a[i][w])
                dp[mask | (1 << w)] = (dp[mask | (1 << w)] + dp[mask]) % MOD;
        }
    }
    
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}