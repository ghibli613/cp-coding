vector<int> weight, profit;
vector<vector<int>> dp;

int knapsack(int N, int W)
{
    dp.assign(N + 1, vector<int>(W + 1, 0));

    for (int j = 0; j <= W; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= weight[i - 1] && dp[i][j] < dp[i - 1][j - weight[i - 1]] + profit[i - 1])
            {
                dp[i][j] = dp[i - 1][j - weight[i - 1]] + profit[i - 1];
            }
        }

    return dp[N][W];
}

void trace(int N, int W)
{
    int totalWeight = 0, totalProfit = 0;
    while (N > 0 && W > 0)
    {
        if (weight[N - 1] <= W && dp[N][W] == dp[N - 1][W - weight[N - 1]] + profit[N - 1])
        {
            cout << weight[N - 1] << " - " << profit[N - 1] << "\n";
            totalWeight += weight[N - 1];
            totalProfit += profit[N - 1];
            W -= weight[N - 1];
        }
        N--;
    }
    cout << "Total weight: " << totalWeight << "\n";
    cout << "Total profit: " << totalProfit << "\n";
}

void test()
{
    int n, w; cin >> n >> w;
    weight.resize(n);
    profit.resize(n);
    for(int i = 0; i < n; i++)
        cin >> weight[i] >> profit[i];

    knapsack(n, w);
    trace(n, w);
}