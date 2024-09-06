#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Edge
{
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0)
        : u(u), v(v), w(w) {}
    
    bool operator<(const Edge& other) const
    {
        return w < other.w;
    }
};

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
    vector<Edge> edges;
    int n, m;

    Graph(int n = 0, int m = 0): n(n), m(m)
    {
        for(int i = 0; i < m; i++)
        {
            int u, v, w; cin >> u >> v >> w;
            edges.push_back(Edge(u, v, w));
        }
    }

    int kruskal()
    {
        int mst = 0;
        int cnt = 0;
    
        sort(edges.begin(), edges.end());
        DisjointSet djs(n);
    
        for(int u, v, w, i = 0; i < m; i++)
        {
            u = edges[i].u;
            v = edges[i].v;
            w = edges[i].w;
    
            if(djs.unionSet(u, v))
            {
                cnt++;
                mst += w;
            }
        }
        return cnt == n - 1 ? mst : -1;
    }
};

void solve()
{
    int n, m; cin >> n;
    vector<int> q(n);
    for(int i = 0; i < n; i++) cin >> q[i];
    cin >> m;
    Graph g(n, m);
    cout << g.kruskal();
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