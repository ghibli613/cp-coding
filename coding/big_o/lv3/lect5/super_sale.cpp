#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int N, P, W, G, MW, ans = 0;
    int dp[31] = {};

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> P >> W;
        for (int j = 30; j >= W; j--)
            if (dp[j] < dp[j - W] + P)
                dp[j] = dp[j - W] + P;
    }
    
    cin >> G;
    while (G--)
    {
        cin >> MW;
        ans += dp[MW];
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}