#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 7;

ll sum_dist[N];
ll a[N];
ll sum[N];
vector<int> graph[N];
int n;

ll dfs1(int u, int p = -1, int d = 0)
{
    sum_dist[1] += d * a[u];
    sum[u] = a[u];
    for(int v : graph[u])
        if(v != p)
            sum[u] += dfs1(v, u, d + 1);
    return sum[u];
}

void dfs2(int u, int p = -1)
{
    for(int v : graph[u])
    {
        if(v != p)
        {
            sum[u] -= sum[v];
            sum_dist[v] = sum_dist[u] - sum[v] + sum[u];
            sum[v] += sum[u];
            dfs2(v, u);
            sum[v] -= sum[u];
            sum[u] += sum[v];
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int u, v, i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs1(1);
    // cout << sum[5];
    dfs2(1);

    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, sum_dist[i]);
    cout << ans;
}