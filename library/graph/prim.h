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