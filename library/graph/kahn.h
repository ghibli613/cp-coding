bool kahn()
{
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0)
            q.push(i);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        result.push_back(u);
        for(int i = 0; i < (int)graph[u].size(); i++)
        {
            indegree[graph[u][i]]--;
            if(indegree[graph[u][i]] == 0)
            {
                q.push(graph[u][i]);
            }
        }
    }
    return result.size() == n;
}