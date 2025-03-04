vector<vector<int>> graph;
vector<int> visited;
vector<int> result;
int n, m;

void dfs(int u)
{
    visited[u] = true;
    for(int v : graph[u])
    {
        if(!visited[v])
            dfs(v);
    }
    result.push_back(u);
}

void test()
{
    cin >> n >> m;
    graph.assign(n + 1, vector<int>());
    visited.assign(n + 1, 0);

    for(int u, v, i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
        if(!visited[i])
            dfs(i);
    for(int i = n - 1; i >= 0; i--)
        cout << result[i] << " ";
}