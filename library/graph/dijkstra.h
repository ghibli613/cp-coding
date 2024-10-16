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