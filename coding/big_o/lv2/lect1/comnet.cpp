#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct Edge
{
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0)
        : u(u), v(v), w(w) {}
};

vector<Edge> e;
vector<vector<pii>> adj;

void solve()
{
    int n, m, q; cin >> n >> m >> q;
    e = vector<Edge>(m);
    adj.assign(n, vector<pii>());
    for(int i = 0; i < m; i++)
    {
        Edge tmp; cin >> tmp.u >> tmp.v >> tmp.w;
        tmp.u--; tmp.v--;
        e[i] = tmp;
        adj[tmp.u].push_back({tmp.v, tmp.w});
        adj[tmp.v].push_back({tmp.u, tmp.w});
    }
    
    while(q--)
    {
        int k, s; cin >> k >> s;
        
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