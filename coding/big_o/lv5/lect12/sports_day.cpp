#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<ll> score(1 << n);
    for(int mask = 0; mask < 1 << n; mask++)
        for(int i = 0; i < n; i++)
            if(mask >> i & 1)
                for(int j = i + 1; j < n; j++)
                    if(mask >> j & 1)
                        score[mask] += a[i][j];

    vector<vector<ll>> dp(k + 1, vector<ll>(1 << n, -(ll)1e18));
    dp[0][0] = 0;
    for(int i = 1; i <= k; i++)
        for(int mask = 0; mask < 1 << n; mask++)
            for(int sub = mask; sub > 0; sub = (sub - 1) & mask)
            {
                int rem = (mask ^ sub);
                dp[i][mask] = max(dp[i][mask], dp[i - 1][rem] + score[sub]);
            }

    cout << dp[k][(1 << n) - 1];

    return 0;
}