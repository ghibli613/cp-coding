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
    int n; cin >> n;
    DisjointSet s(n);
    vector<pii> a(n);
    vector<pii> dup_ci;
    int ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a[i].first >> a[i].second;
        bool check = s.unionSet(a[i].first, a[i].second);
        if(check == false) 
        {
            ans++;
            dup_ci.push_back({a[i].first, a[i].second});
        }
    }
    vector<bool> cities(n + 1, false);
    for(int i = 1; i < n + 1; i++)
    {
        int p = s.findSet(i);
        cities[p] = true;
    }
    vector<int> set_cities;
    for(int i = 1; i < n + 1; i++)
    {
        if(cities[i]) set_cities.push_back(i);
    }
    cout << ans << '\n';
    for(int i = 0; i < (int)set_cities.size() - 1; i++)
    {
        cout << dup_ci[i].first << ' ' << dup_ci[i].second << ' ' << set_cities[i] << ' ' << set_cities[i + 1] << '\n'; 
    }
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