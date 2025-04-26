#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[2][2520][1 << 10][2];

ll solve(ll num, int k)
{
    if (num <= 0)
        return 0;
    string s = to_string(num);
    int n = s.size();

    memset(dp, 0, sizeof(dp));
    dp[0][0][0][1] = 1;
    for (int i = 0; i < n; i++)
    {
        memset(dp[(i + 1) % 2], 0, sizeof(dp[0]));
        for (int j = 0; j < 2520; j++)
            for (int mask = 0; mask < (1 << 10); mask++)
                for (int tight = 0; tight < 2; tight++)
                {
                    if (dp[i % 2][j][mask][tight] == 0)
                        continue;
                    for (int d = 0; d <= (tight ? (s[i] - '0') : 9); d++)
                        dp[(i + 1) % 2][(j * 10 + d) % 2520][mask | (1 << d)][tight && (d == s[i] - '0')] += dp[i % 2][j][mask][tight];
                }
    }

    ll ans = 0;
    for (int i = 0; i < 2520; i++)
        for (int mask = 0; mask < (1 << 10); mask++)
        {
            int c = 0;
            for (int bit = 1; bit < 10; bit++)
                if (((mask >> bit) & 1) && (i % bit == 0))
                    c++;
            
            if (c < k)
                continue;
            for (int tight = 0; tight < 2; tight++)
                ans += dp[n % 2][i][mask][tight];
        }
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q-- > 0)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        cout << solve(r, k) - solve(l - 1, k) << endl;
    }
    return 0;
}