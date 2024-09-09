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


void solve()
{
    int n, k; cin >> n >> k;
    DisjointSet dsu(n);
    vector<bool> type(k), ans(k);
    vector<pii> query(k);
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) cin >> p[i];

    for(int i = 0; i < k; i++)
    {
        char q; cin >> q;
        if(q == 'C')
        {
            int x; cin >> x;
            type[i] = 1;
            query[i] = {x, p[x]};
            p[x] = 0;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            type[i] = 0;
            query[i] = {x,y};
        }
    }
    
    for(int i = 1; i <= n; ++i)
    {
        if(p[i]) dsu.unionSet(p[i], i);
    }
    
    for(int i = k - 1; i >= 0; --i)
    {
        if(type[i] && query[i].second)
        {
            dsu.unionSet(query[i].second, query[i].first);
        }
        else
        {
            ans[i] = (dsu.findSet(query[i].first) == dsu.findSet(query[i].second));
        }
    }
    for(int i = 0; i < k; ++i)
    {
        if(type[i] == 0)
        {
            cout << (ans[i] ? "YES\n" : "NO\n");
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": \n";
        solve();
    }

    return 0;
}