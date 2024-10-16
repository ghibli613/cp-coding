bool topo_dfs(int u)
{
    visited[u] = 1;
    for(int i = 0; i < (int)graph[u].size(); i++)
    {
        if(visited[graph[u][i]] == 1)
        {
            return false;
        }
        if(visited[graph[u][i]] == 0)
        {
            if(topo_dfs(graph[u][i]) == false)
                return false;
        }
    }
    result.push_back(u);
    visited[u] = 2;
    return true;
}