#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
vector<vector<pii>> adj;
vector<int> dist;
int l;
int res = 0;

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty())
    {
        pii tmp = pq.top(); pq.pop();
        int u = tmp.second;
        if(tmp.first != dist[u]) continue;
        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void check(int u, int v, int w)
{
    if (dist[u] < l && dist[v] < l && 2 * l == dist[u] + dist[v] + w){
        res++;
        return;
    }
    if (dist[u] < l && dist[u] + w > l && dist[u] + dist[v] + w > 2 * l) res++;
    if (dist[v] < l && dist[v] + w > l && dist[u] + dist[v] + w > 2 * l) res++;
}

void solve()
{
    int n, m, s; cin >> n >> m >> s;
    s -= 1;
    adj.assign(n, vector<pii>());
    dist.assign(n, 1e9);
    vector<int> u(m), v(m), w(m);
    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        u[i] -= 1; v[i] -= 1;
        adj[u[i]].push_back({v[i], w[i]});
        adj[v[i]].push_back({u[i], w[i]});
    }
    cin >> l;
    dijkstra(s);
    for(int i = 0; i < n; i++)
        if(dist[i] == l) res++;
    
    for(int i = 0; i < m; i++)
    {
        check(u[i], v[i], w[i]);
    }
    cout << res;
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