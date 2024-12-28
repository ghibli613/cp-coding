int coinChange(vector<int> &coins, int n, int w)
{
    dp[0] = 0;
    for(int i = 1; i <= w; i++)
        dp[i] = INF;

    for(int i = 1; i <= n; i++)
        for(int j = coins[i - 1]; j <= w; j++)
            dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
    
    return dp[w];
}

void trace(vector<int> &coins, int n, int w)
{
    while(w > 0)
    {
        if(w >= coins[n - 1] && dp[w] == dp[w - coins[n - 1]] + 1)
        {
            cout << coins[n - 1] << " ";
            w -= coins[n - 1];
        }
        else
            n -= 1;
    }
}