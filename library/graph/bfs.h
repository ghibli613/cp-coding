void bfs(int s)
{
    int sz = adj.size();
    path.assign(sz, -1);
    visited.assign(sz, false);
    queue<int> q;

    q.push(s);
    visited[s] = true;

    int u, v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                path[v] = u;
                q.push(v);
            }
        }
    }
}