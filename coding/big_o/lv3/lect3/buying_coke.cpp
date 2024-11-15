#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int oo = 1e9;

void solve()
{
    int c, n1, n5, n10;
    cin >> c >> n1 >> n5 >> n10;
    vector<vector<vector<int>>> dp(c + 1, vector<vector<int>>(n5 + c + 2, vector<int>(n10 + 1, oo)));
    dp[0][0][0] = 0;
    for(int j = 0; j <= n5 + c + 1; j++)
        for(int k = 0; k <= n10; k++) dp[0][j][k] = 0;
            
    for(int i = 1; i <= c; i++)
    {
        for(int j = 0; j <= n5 + c; j++)
        {
            for(int k = 0; k <= n10; k++)
            {
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + 8);
                if(j > 0) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k] + 4);
                if(j > 1) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 2][k] + 2);
                if(k > 0) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - 1] + 1);
                if(k > 0) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j + 1][k - 1] + 4);
            }
        }
    }

    cout << dp[c][n5][n10] << '\n';
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