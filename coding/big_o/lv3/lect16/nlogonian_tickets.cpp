#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 5;
int n, dep[N];
int par[N][20], Max[N][20];
vector<pii> adj[N];

void dfs(int u, int pu = -1, int hei = 0)
{
    dep[u] = hei;
    for (pii it : adj[u])
    {
        int v = it.first, w = it.second;
        if (v == pu)
            continue;
        dfs(v, u, hei + 1);
        par[v][0] = u;
        Max[v][0] = w;
    }
}

void build()
{
    dfs(1);

    for (int j = 1; j < 20; j++)
        for (int i = 1; i <= n; i++)
        {
            int x = par[i][j - 1];
            par[i][j] = par[x][j - 1];
            Max[i][j] = max(Max[i][j - 1], Max[x][j - 1]);
        }
}

int getMaxEdge(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    int maxEdge = 0;

    int LOG = log2(dep[u]) + 1;

    for (int j = LOG; j >= 0; j--)
        if (dep[u] - (1 << j) >= dep[v])
        {
            maxEdge = max(maxEdge, Max[u][j]);
            u = par[u][j];
        }

    if (u == v)
        return maxEdge;

    for (int j = LOG; j >= 0; j--)
    {
        int au = par[u][j], av = par[v][j];
        if (au == 0 || au == av)
            continue;
        maxEdge = max(maxEdge, Max[u][j]);
        maxEdge = max(maxEdge, Max[v][j]);
        u = au, v = av;
    }

    maxEdge = max(maxEdge, Max[u][0]);
    maxEdge = max(maxEdge, Max[v][0]);

    return maxEdge;
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n, n != 0)
    {
        for (int i = 1; i < n; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        build();

        int q;
        cin >> q;
        for (int i = 1; i <= q; i++)
        {
            int a, b;
            cin >> a >> b;
            cout << getMaxEdge(a, b) << '\n';
        }

        for (int i = 1; i <= n; i++)
            adj[i].clear();
    }

    return 0;
}