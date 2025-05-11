#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e3 + 7;

int a[N];
ll dp[N][N];
int opt[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while(cin >> n >> m)
    {
        for(int i = 1; i <= m; i++)
            cin >> a[i];
        a[m + 1] = n;
        for(int i = 0; i <= m; i++)
            opt[i][i + 1] = i;

        for(int len = 2; len <= m + 1; len++)
            for(int i = 0; i <= m + 1 - len; i++)
            {
                int j = len + i;
                dp[i][j] = (ll)1e18;
                for(int k = opt[i][j - 1]; k <= opt[i + 1][j]; k++)
                    if(dp[i][j] > dp[i][k] + dp[k][j])
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        opt[i][j] = k;
                    }
                dp[i][j] += a[j] - a[i];
            }
        cout << dp[0][m + 1] << '\n';
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        memset(opt, 0, sizeof(opt));
    }

    return 0;
}