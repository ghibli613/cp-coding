#include <bits/stdc++.h>
using namespace std;

double dp[2005][2005];

int main()
{
    double p;
    int n, t;
    cin >> n >> p >> t;
    dp[0][0] = 1;
    for (int i = 1; i <= t; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if(j == 0)
                dp[i][j] += dp[i - 1][j] * (1 - p);
            else if(j == n)
                dp[i][j] += dp[i - 1][j - 1] * p + dp[i - 1][j];
            else
                dp[i][j] += dp[i - 1][j - 1] * p + dp[i - 1][j] * (1.0 - p);
        }
    }

    double ans = 0;
    for (int i = 1; i <= n; i++)
        ans += dp[t][i] * i;
    cout << fixed << setprecision(6) << ans;
}