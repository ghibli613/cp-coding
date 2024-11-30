#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;

    while (cin >> m)
    {
        int n;
        cin >> n;
        vector<int> profit(n), weight(n);
        for (int i = 0; i < n; i++)
            cin >> weight[i] >> profit[i];

        int w = m;
        if (m > 1800)
            w += 200;
        vector<int> dp(w + 1, 0);

        for (int i = 0; i < n; i++)
            for (int j = w; j >= weight[i]; j--)
            {
                if (dp[j - weight[i]] != 0 || j == weight[i])
                    dp[j] = max(dp[j], dp[j - weight[i]] + profit[i]);
            }

        int ans = 0;
        if (m >= 1801 && m <= 2000)
        {
            for (int i = 1; i <= m; i++)
                ans = max(ans, dp[i]);
            for (int j = 2001; j <= w; ++j)
                ans = max(ans, dp[j]);
        }
        else
            for (int i = 1; i <= w; i++)
                ans = max(ans, dp[i]);
        cout << ans << '\n';
    }

    return 0;
}