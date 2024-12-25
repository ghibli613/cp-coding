#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Graph
{
    int n, level;
    vector<vector<int>> graph;
    int counter;
    vector<int> tin, tout;
    vector<vector<int>> parent;
    vector<vector<ll>> parent_dist;
    map<pair<int, int>, ll> dist_map;
    
    Graph(int n_)
    {
        n = n_;
        graph.assign(n + 1, vector<int>());
        tin.assign(n + 1, 0); tout.assign(n + 1, 0);
    
        level = ceil(log2(n));
        parent.assign(n + 1, vector<int>(level));
        parent_dist.assign(n + 1, vector<ll>(level, 0));
        for(int i = 2; i <= n; i++)
        {
            int a; ll l;
            cin >> a >> l;
            a++;
            graph[i].push_back(a);
            graph[a].push_back(i);
            dist_map[{a, i}] = l;
            dist_map[{i, a}] = l;
        }
    }
    
    void dfs(int u, int p)
    {
        tin[u] = ++counter;
    
        parent[u][0] = p;
        parent_dist[u][0] = dist_map[{u, p}];
        for(int v : graph[u])
            if(v != p)
                dfs(v, u);
    
        tout[u] = ++counter;
    }
    
    void preprocess(int root)
    {
        counter = 0;
        dfs(root, root);
    
        for(int k = 1; k < level; k++)
            for(int i = 1; i <= n; i++)
                parent[i][k] = parent[parent[i][k - 1]][k - 1];

        for(int k = 1; k < level; k++)
            for(int i = 1; i <= n; i++)
                parent_dist[i][k] = parent_dist[parent[i][k - 1]][k - 1] + parent_dist[i][k - 1];
    }
    
    int isAncestor(int u, int v)
    {
        return tin[u] <= tin[v] && tin[v] <= tout[u];
    }
    
    int lca(int u, int v)
    {
        if(isAncestor(u, v)) return u;
        if(isAncestor(v, u)) return v;
    
        for(int k = level - 1; k >= 0; k--)
            if(!isAncestor(parent[u][k], v))
                u = parent[u][k];
    
        return parent[u][0];
    }

    ll dist(int u, int p)
    {
        ll res = 0;
        for(int k = level - 1; k >= 0; k--)
            if(!isAncestor(parent[u][k], p))
            {
                res += parent_dist[u][k];
                u = parent[u][k];
            }
        res += dist_map[{u, p}];
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n, n != 0)
    {
        Graph g(n);
        g.preprocess(1);
        int q, u, v;
        cin >> q;
        while(q--)
        {
            cin >> u >> v;
            u++, v++;
            int lca_uv = g.lca(u, v);
            // cout << lca_uv << endl;
            ll ans = g.dist(u, lca_uv) + g.dist(v, lca_uv);
            cout << ans << ' ';
            // cout << u << ' ' << lca_uv << ' ' << g.dist(u, lca_uv) << endl;
        }
        cout << endl;
    }

    return 0;
}