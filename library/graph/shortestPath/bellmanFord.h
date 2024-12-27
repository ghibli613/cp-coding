#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

const int INF = 1e9;

struct Edge
{
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0)
        : u(u), v(v), w(w) {}
};

vector<int> dist, path;

int bellmanFord(vector<Edge> &edges, int n, int m, int s)
{
    dist.assign(n + 1, INF);
    path.assign(n + 1, -1);
    dist[s] = 0;
    int u, v, w;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            u = edges[j].u;
            v = edges[j].v;
            w = edges[j].w;
            if(dist[u] != INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }

    // check negative cycle
    for(int j = 0; j < m; j++)
    {
        u = edges[j].u;
        v = edges[j].v;
        w = edges[j].w;
        if(dist[u] != INF && dist[v] > dist[u] + w)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    int u, v, w;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    bellmanFord(edges, n, m, 1);
    cout << dist[n];
}