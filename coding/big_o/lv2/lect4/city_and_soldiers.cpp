#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct DisjointSet
{
    vector<int> parent, Rank, leader;
    DisjointSet(int n): parent(n + 1), Rank(n + 1, 0), leader(n + 1)
    {
        for (int i=1; i<=n; i++) 
        {
            parent[i] = i;
            leader[i] = i;
        }
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
        if(Rank[pu] > Rank[pv]) 
        {
            parent[pv] = pu;
            leader[pu] = leader[pv];
        }
        else if(Rank[pu] < Rank[pv]) parent[pu] = pv;
        else
        {
            parent[pv] = pu;
            leader[pu] = leader[pv];
            Rank[pu]++;
        }
        return true;
    }
    void operate(int q)
    {
        for(int i = 0; i < q; i++)
        {
            int type; cin >> type;
            if(type == 1)
            {
                int a, b; cin >> a >> b;
                unionSet(a, b);
            }
            else if(type == 2)
            {
                int a; cin >> a;
                leader[findSet(a)] = a;
            }
            else 
            {
                int a; cin >> a;
                cout << leader[findSet(a)] << '\n';
            }
        }
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    DisjointSet dsu(n);
    dsu.operate(q);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    for(int tc = 1; tc <= t; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}