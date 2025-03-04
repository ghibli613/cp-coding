typedef pair<int, int> pii;
typedef pair<int, pii> piii;

vector<piii> edges;
int n, m;

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

int kruskal()
{
    int mst = 0;
    int cnt = 0;

    sort(edges.begin(), edges.end());
    DisjointSet dsu(n);

    for(int u, v, w, i = 0; i < m; i++)
    {
        u = edges[i].second.first;
        v = edges[i].second.second;
        w = edges[i].first;

        if(dsu.unionSet(u, v))
        {
            cnt++;
            mst += w;
        }
    }
    return cnt == n - 1 ? mst : -1;
}

void test()
{
    cin >> n >> m;
    for(int u, v, w, i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edges.push_back(make_pair(w, make_pair(u, v)));
    }

    int mst = kruskal();
    if(mst == -1)
        cout << "Graph is not connect\n";
    else
        cout << mst << "\n";
}