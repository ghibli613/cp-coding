#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> b(n + 1);
    b[0] = 1;
    for (int i = 1; i <= n; i++)
        b[i] = 1 << i;

    vector<vector<ll>> c(n, vector<ll>(n));
    while (k--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        c[x - 1][y - 1] = z;
    }

    vector<vector<ll>> dp((1 << n), vector<ll>(n));
    for (int i = 0; i < n; i++)
        dp[b[i]][i] = a[i];

    for (int mask = 0; mask < b[n]; mask++)
        for (int i = 0; i < n; i++)
            if (mask & b[i])
            {
                for (int j = 0; j < n; j++)
                    if ((mask & b[j]) == 0)
                        dp[(mask | b[j])][j] = max(dp[(mask | b[j])][j], dp[mask][i] + c[i][j] + a[j]);
            }

    ll res = 0;
    for (int mask = 0; mask < b[n]; mask++)
        if (__builtin_popcount(mask) == m)
            for (int i = 0; i < n; i++)
                res = max(res, dp[mask][i]);

    cout << res << "\n";
}