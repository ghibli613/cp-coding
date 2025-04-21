#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

int n, q;
vector<pair<int, int>> tree[105];
int dp[105][105];
int num[105];

void dfs(int u, int p)
{
    num[u] = 1;
    for(pair<int, int> x : tree[u])
    {
        int v = x.first;
        if(v == p) continue;
        
        dfs(v, u);
        num[u] += num[v];
        for(int i = num[u]; i > 0; i--)
            for(int j = 1; j < i && j <= num[v]; j++)
                dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j] + x.second);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        tree[u].push_back({v, c});
        tree[v].push_back({u, c});
    }
    dfs(1, 0);
    cout << dp[1][q + 1];

    return 0;
}