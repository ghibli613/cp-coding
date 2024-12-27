#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

const int INF = 1e9;

typedef pair<int, int> pii;

vector<int> dist, path;
vector<bool> visited;
vector<vector<pii>> adj;
int n, m;

bool prim()
{
    dist.assign(n, INF);
    path.assign(n, -1);
    visited.assign(n, false);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    int count = 0;
    while(!pq.empty())
    {
        pii tmp = pq.top(); pq.pop();
        int u = tmp.second;
        if(visited[u]) continue;
        visited[u] = true;
        count++;
        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(!visited[v] && dist[v] > w)
            {
                dist[v] = w;
                path[v] = u;
                pq.push({w, v});
            }
        }
    }
    return count == n;
}

int main()
{
    cin >> n >> m;

    adj.assign(n, vector<pii>());
    for(int u, v, w, i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    if(!prim()) cout << "Graph is not connect\n";
    else
    {
        int mst = 0;
        for(int i = 0; i < n; i++)
            mst += dist[i];
        cout << "MST: " << mst << "\n";
    }
    return 0;
}