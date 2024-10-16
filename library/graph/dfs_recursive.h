void dfs(int s)
{
    visited[s] = true;

    for(int i = 0; i < (int)adj[s].size(); i++)
    {
        int v = adj[s][i];

        if(!visited[v])
        {
            path[v] = s;
            dfs(v);
        }
    }
}