#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

set <pair <int, pii>> s;
int n, q;

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

int solve(int x, int y, int z)
{
    DisjointSet djs(200);
    s.insert({z, {x, y}});
    int res = 0;
    for (auto it = s.begin(); it != s.end(); it++) 
    {
        int a = (*it).second.first, b = (*it).second.second;
        if (djs.findSet(a) != djs.findSet(b))
        {
            djs.unionSet(a, b);
            res += (*it).first;
        }
    }
    int ok = 1;
    for (int i = 1; i <= n; i++) 
    {
        if (djs.findSet(i) != djs.findSet(1)) 
        {
            ok = 0; break;
        }
    }
    if (ok == 0) return -1;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < q; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        cout << solve(a, b, c) << '\n';
    }

    return 0;
}