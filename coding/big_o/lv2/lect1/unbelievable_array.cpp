#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int color[100001];

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
        color[pu] = color[pv];
        if(pu == pv) return false;
        if(Rank[pu] > Rank[pv]) 
        {
            parent[pv] = pu;
        }
        else if(Rank[pu] < Rank[pv]) 
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pv] = pu;
            Rank[pu]++;
        }
        return true;
    }
};

void solve(int tc)
{
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    DisjointSet s(100000);

    for(int i = 1; i <= 100000; i++) color[i] = i;

    cout << "Case " << tc << ":\n";
    for(int i = 0; i < q; i++)
    {
        int t; cin >> t;
        if(t == 1)
        {
            int x, y; cin >> x >> y;
            s.unionSet(x, y);
        }
        else
        {
            int idx; cin >> idx;
            cout << color[s.findSet(a[idx])] << '\n';
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
        solve(tc);

    return 0;
}