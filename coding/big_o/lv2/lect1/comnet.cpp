#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

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
    int n, m, q; cin >> n >> m >> q;
    vector<pii> e(m);
    vector<int> w(m);
    for(int i = 0; i < m; i++)
    {
        cin >> e[i].first >> e[i].second >> w[i];
    }
    
    while(q--)
    {
        int k, s; cin >> k >> s;
        k--;
        vector<int> ww = w;
        while(s--)
        {
            int t, c; cin >> t >> c;
            ww[t - 1] = c;
        }
        DisjointSet a(n);
        for(int i = 0; i < m; i++) 
            if(ww[i] < ww[k]) 
            {
                a.unionSet(e[i].first, e[i].second);
            }
        if (a.unionSet(e[k].first, e[k].second)) cout << "NO\n";
        else cout << "YES\n";
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}