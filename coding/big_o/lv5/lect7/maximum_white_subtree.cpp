#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> dp;
vector<int> ans;
vector<vector<int>> g;

void dfs(int v, int p = -1)
{
    dp[v] = a[v];
    for (int to : g[v])
    {
        if (to == p)
            continue;
        dfs(to, v);
        dp[v] += max(dp[to], 0);
    }
}

void dfs2(int v, int p = -1)
{
    ans[v] = dp[v];
    for (int to : g[v])
    {
        if (to == p)
            continue;
        dp[v] -= max(0, dp[to]);
        dp[to] += max(0, dp[v]);
        dfs2(to, v);
        dp[to] -= max(0, dp[v]);
        dp[v] += max(0, dp[to]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    a = dp = ans = vector<int>(n);
    g = vector<vector<int>>(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] == 0)
            a[i] = -1;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0);
    dfs2(0);

    for (int it : ans)
        cout << it << " ";

    return 0;
}