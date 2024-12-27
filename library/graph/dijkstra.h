#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

const int INF = 1e9;

typedef pair<int, int> pii;

vector<int> dist, path;
vector<vector<pii>> adj;
int n, m;

void dijkstra(int s)
{
    dist.assign(n, INF);
    path.assign(n, -1);
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
                path[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    adj.assign(n, vector<pii>());
    int u, v, w;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstra(0);

    for(int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}