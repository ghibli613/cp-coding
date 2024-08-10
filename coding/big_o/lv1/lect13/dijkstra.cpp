#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> dist;
vector<int> path;
vector<vector<pii>> adj;

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[0] = 0;

    while(!pq.empty())
    {
        pii tmp = pq.top(); pq.pop();

        int u = tmp.second;
        if(tmp.first != dist[u]) continue;

        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            int w = adj[u][i].first;
            int v = adj[u][i].second;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                path[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    dist.assign(n, 1e9);
    path.assign(n, -1);
    adj.assign(n, vector<pii>());

    for(int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        adj[u - 1].push_back({w, v - 1});
        adj[v - 1].push_back({w, u -1});
    }

    dijkstra(0);

    if(dist[n - 1] == (int)1e9) cout << -1;
    else
    {
        stack<int> ans;
        int tmp = n - 1;
        ans.push(tmp + 1);
        while(tmp)
        {
            tmp = path[tmp];
            ans.push(tmp + 1);
        }
        while(!ans.empty())
        {
            cout << ans.top() << ' ';
            ans.pop();
        }
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