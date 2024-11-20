#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q, d, m;
ll a[205] = {};
ll dp[205][15][25] = {};

void solve()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        dp[i][0][0] = 1;
        for(int j = 1; j <= min(i, m); j++)
            for(int k = 0; k < d; k++)
            {
                dp[i][j][k] += dp[i - 1][j][k];
                ll tmp = (k + a[i]) % d;
                if(tmp < 0) tmp += d;
                dp[i][j][tmp] += dp[i - 1][j - 1][k];
            }
    }
    cout << dp[n][m][0] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while(true)
    {
        cin >> n >> q;
        if(n == 0 && q == 0)
            break;
        
        cout << "SET " << t << ":\n";
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        
        for(int i = 1; i <= q; i++)
        {
            cout << "QUERY " << i << ": ";
            cin >> d >> m;
            solve();
        }

        t++;
    }   

    return 0;
}