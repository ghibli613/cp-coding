int lcs(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    return dp[n][m];
}

void trace(vector<int>& a, vector<int>& b)
{
    int n = a.size(), m = b.size();

    vector<int> res;
    while(n > 0 && m > 0)
    {
        if(a[n - 1] == b[m - 1])
        {
            res.push_back(a[n - 1]);
            n--;
            m--;
        }
        else if(dp[n - 1][m] > dp[n][m - 1])
            n--;
        else
            m--;
    }
    for(int i = res.size() - 1; i >= 0; i++)
        cout << res[i] << " ";
}