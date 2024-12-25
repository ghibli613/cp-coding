#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Graph
{
    int n, level;
    vector<vector<int>> graph;
    int counter;
    vector<int> tin, tout;
    vector<vector<int>> parent;
    vector<int> depth;

    Graph(int n_)
    {
        n = n_;
        graph.assign(n + 1, vector<int>());
        tin.assign(n + 1, 0);
        tout.assign(n + 1, 0);
        depth.assign(n + 1, 0);

        level = ceil(log2(n));
        parent.assign(n + 1, vector<int>(level));
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    void dfs(int u, int p)
    {
        depth[u] = depth[p] + 1;
        tin[u] = ++counter;

        parent[u][0] = p;
        for (int v : graph[u])
            if (v != p)
                dfs(v, u);

        tout[u] = ++counter;
    }

    void preprocess(int root)
    {
        counter = 0;
        dfs(root, root);

        for (int k = 1; k < level; k++)
            for (int i = 1; i <= n; i++)
                parent[i][k] = parent[parent[i][k - 1]][k - 1];
    }

    int isAncestor(int u, int v)
    {
        return tin[u] <= tin[v] && tin[v] <= tout[u];
    }

    int lca(int u, int v)
    {
        if (isAncestor(u, v))
            return u;
        if (isAncestor(v, u))
            return v;

        for (int k = level - 1; k >= 0; k--)
            if (!isAncestor(parent[u][k], v))
                u = parent[u][k];

        return parent[u][0];
    }

    int getParent(int u, int p)
    {
        if (p == 0)
            return u;
        while (p)
        {
            int k = log2(p);
            u = parent[u][k];
            p -= 1 << k;
        }
        return u;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        Graph g(n);
        g.preprocess(1);
        int q, u, v;
        cin >> q;
        while (q--)
        {
            cin >> u >> v;
            int uv_lca = g.lca(u, v);
            int dist = g.depth[u] + g.depth[v] - 2 * g.depth[uv_lca];
            int pos;
            if (g.depth[u] > g.depth[v])
                pos = g.getParent(u, dist/2);
            else 
                pos = g.getParent(v, dist/2);
            if(dist % 2 == 0 ) 
                cout << "The fleas meet at " << pos <<"." << endl;
            else
                cout << "The fleas jump forever between " << min(pos, g.parent[pos][0]) << " and " << max(pos, g.parent[pos][0]) << "." << endl;
        }
    }

    return 0;
}