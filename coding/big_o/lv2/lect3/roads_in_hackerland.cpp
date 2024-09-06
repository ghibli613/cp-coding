#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct DisjointSet
{
    vector<int> parent, Rank;
    DisjointSet(int n): parent(n + 1), Rank(n + 1, 0)
    {
        for (int i=1; i<=n; i++) parent[i] = i;
    }
    int findSet(int u)
    {
        if (parent[u] != u) parent[u] = findSet(parent[u]);
        return parent[u];
    }
    bool unionSet(int u, int v)
    {
        int pu = findSet(u), pv = findSet(v);
        if(pu == pv) return false;
        if(Rank[pu] > Rank[pv]) parent[pv] = pu;
        else if(Rank[pu] < Rank[pv]) parent[pu] = pv;
        else
        {
            parent[pv] = pu;
            Rank[pu]++;
        }
        return true;
    }
};

struct Graph
{
    vector<pair<int, pii>> adj;
    vector<vector<pii>> graph;
    vector<ll> ans;
    int n, m, max_w;

    Graph(int n = 0, int m = 0): n(n), m(m), max_w(0), 
    graph(n + 1, vector<pii>()),
    ans(200007, 0)
    {
        for(int i = 0; i < m; i++)
        {
            int u, v, w; cin >> u >> v >> w;
            adj.push_back({w, {u, v}});
        }
    }

    void kruskal()
    {

        sort(adj.begin(), adj.end());
        DisjointSet djs(n);
        for(int i = 0; i < m; i++)
        {
            int u, v; ll w;
            u = adj[i].second.first;
            v = adj[i].second.second;
            w = adj[i].first;
            if(djs.unionSet(u, v))
            {
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
                if(w > max_w) max_w = w;
            }
        }
    }

    ll dfs(int u, int p, int b)
    {
        ll count = 1;
        for(int i = 0; i < (int)graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(v == p) continue;
            count += dfs(v, u, w);
        }
        if(b == -1) return 0;
        ans[b] += 1ll * count * (n - count);
        return count;
    }

    void output()
    {
        for(int i = 0; i <= max_w; i++)
        {
            ans[i + 1] += ans[i] / 2;
            ans[i] %= 2;
            if(ans[i + 1] > 0)
            {
                max_w = max(max_w, i + 1);
            }
        }

        for(int i = max_w; i >= 0; i--)
        {
            cout << ans[i];
        }
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    Graph g(n, m);
    g.kruskal();
    g.dfs(1, 0, -1);

    g.output();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}