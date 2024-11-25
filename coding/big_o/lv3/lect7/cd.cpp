#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int w;
    while (cin >> w)
    {
        int n;
        cin >> n;
        vector<int> weight(n);
        for (int i = 0; i < n; i++)
            cin >> weight[i];

        vector<vector<int>> dp(n + 1, vector<int> (w + 1, 0));

        for(int j = 0; j <= w; j++) dp[0][j] = 0;
        
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= w; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(j >= weight[i - 1] && dp[i][j] < dp[i - 1][j - weight[i - 1]] + weight[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - weight[i - 1]] + weight[i - 1];
                }
            }
        
        int N = n, W = w;
        while(N > 0 && W > 0)
        {
            if(weight[N - 1] <= W && dp[N][W] == dp[N - 1][W - weight[N - 1]] + weight[N - 1])
            {
                cout << weight[N - 1] << ' ';
                W -= weight[N - 1];
            }
            N--;
        }
        cout << "sum:" << dp[n][w] << '\n';
    }

    return 0;
}