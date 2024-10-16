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