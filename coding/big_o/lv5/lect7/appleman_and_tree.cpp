#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

int n;
int p[N];
int dp[N][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i < n; i++) cin >> p[i];

    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        dp[i][x] = 1;
    }

    for(int v = n - 1; v > 0; v--)
    {
        int u = p[v];
        dp[u][1] = (1LL * dp[u][1] * (dp[v][1] + dp[v][0]) + 1LL * dp[u][0] * dp[v][1]) % MOD;
        dp[u][0] = 1LL * dp[u][0] * (dp[v][1] + dp[v][0]) % MOD;
    }
    cout << dp[0][1];

    return 0;
}