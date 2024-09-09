#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Edge
{
    int u, v, g, s;
    Edge(int u = 0, int v = 0, int g = 0, int s = 0)
        : u(u), v(v), g(g), s(s) {}
    bool operator<(const Edge& other) const
    {
        return g < other.g;
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

void solve()
{
    int n, m; cin >> n >> m;
    ll G, S; cin >> G >> S;
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].g >> edges[i].s;
    }
    sort(edges.begin(), edges.end());
    ll ans = LONG_LONG_MAX;
    vector<Edge> currMST;
    for(int i = 0; i < m; i++)
    {
        currMST.push_back(edges[i]);
        int currentIndex = currMST.size() - 1;
        while(currentIndex > 0 && currMST[currentIndex - 1].s > currMST[currentIndex].s)
        {
            swap(currMST[currentIndex - 1], currMST[currentIndex]);
            currentIndex--;
        }
        DisjointSet dsu(n);
        int removeIndex = - 1;
        for(int j = 0; j < (int)currMST.size(); j++)
        {
            bool check = dsu.unionSet(currMST[j].u, currMST[j].v);
            if(!check) removeIndex = j;
        }
        if(removeIndex != -1)
            currMST.erase(currMST.begin() + removeIndex);
        if((int)currMST.size() == n - 1)
            ans = min(ans, G * edges[i].g + S * currMST[n - 2].s);
    }

    cout << ans;
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