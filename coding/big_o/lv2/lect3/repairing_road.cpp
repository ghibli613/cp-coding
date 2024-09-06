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
    vector<pair<ll,pii>> adj;
    int n, m;

    Graph(int n = 0, int m = 0): n(n), m(m)
    {
        for(int i = 0; i < m; i++)
        {
            int u, v; ll f; cin >> u >> v >> f;
            adj.push_back({f,{u, v}});
        }
    }

    int kruskal()
    {
        ll mst = 0;
        int cnt = 0;

        sort(adj.begin(), adj.end(), greater<pair<ll, pii>>());
        DisjointSet djs(n);
        for(int i = 0; i < m; i++)
        {
            int u, v; ll w;
            u = adj[i].second.first;
            v = adj[i].second.second;
            w = adj[i].first;
            if(djs.unionSet(u, v))
            {
                cnt++;
                mst += w;
            }
        }
        cout << cnt << ' ' << mst << '\n';
        return cnt == n - 1 ? mst : -1;
    }
};

void solve(int tc)
{
    int n, m; cin >> n >> m;
    Graph g(n, m);
    cout << "Case " << tc << ": ";
    g.kruskal();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 1; tc <= t; tc++)
        solve(tc);

    return 0;
}