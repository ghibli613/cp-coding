#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double dp[1010][1010];

void solve()
{
    int n, k; cin >> n >> k;
    vector<double> p(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];

    dp[0][0] = 1.0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= min(i, k); j++)
        {
            dp[i][j] = dp[i - 1][j] * (1.0 - p[i]);
            if(j > 0)
                dp[i][j] += dp[i - 1][j - 1] * p[i];
        }
    cout << fixed << setprecision(10) << dp[n][k] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}