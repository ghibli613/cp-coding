vector<vector<int>> adj;
vector<int> path;
vector<bool> visited;

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

void test()
{
    int n, m; cin >> n >> m;

    adj.assign(n + 1, vector<int>());
    for(int u, v, i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    path.assign(n + 1, -1);
    visited.assign(n + 1, false);
    dfs(1);
}