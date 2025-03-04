int knapsack(int N, int W)
{
    dp.assign(W + 1, 0);

    for(int i = 0; i < N; i++)
        for(int j = W; j >= weight[i]; j--)
        {
            if(dp[j] < dp[j - weight[i]] + profit[i])
                dp[j] = dp[j - weight[i]] + profit[i];
        }

    return dp[W];
}