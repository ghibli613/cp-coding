#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h; cin >> n >> h;
    vector<vector<ll>> dp(40, vector<ll>(40, 0));

    for (int i = 0; i <= n; i++) dp[0][i] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 0; k < i; k++)
                dp[i][j] += dp[k][j - 1] * dp[i - k - 1][j - 1];

    cout << dp[n][n] - dp[n][h - 1];

    return 0;
}