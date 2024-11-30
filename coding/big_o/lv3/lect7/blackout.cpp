#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q, k;
    cin >> n >> m >> q >> k;

    vector<vector<ll>> arr(n + 1, vector<ll>(m + 1, 0));
    vector<ll> dp(k + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }

    while (q--)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll area = (x2 - x1 + 1) * (y2 - y1 + 1);
        ll p = arr[x2][y2] + arr[x1 - 1][y1 - 1] - arr[x1 - 1][y2] - arr[x2][y1 - 1];

        for (int i = k; i - p >= 0; --i)
        {
            if (dp[i - p] >= 0)
            {
                dp[i] = max(dp[i], dp[i - p] + area);
            }
        }
    }

    ll ans = 0;

    for (int i = 0; i <= k; ++i)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}