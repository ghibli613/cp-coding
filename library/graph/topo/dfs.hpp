vector<vector<int>> graph;
vector<int> visited;
vector<int> result;
int n, m;

/*
Value of visited:
- 0: not visit (not process)
- 1: visiting (processing)
- 2: visited (processed)
*/
bool dfs(int u)
{
    visited[u] = 1;
    for(int v : graph[u])
    {
        if(visited[v] == 1) // cycle detected
            return false;
        if(visited[v] == 0)
            if(dfs(v) == false)
            {
                return false;
            }
    }
    result.push_back(u);
    visited[u] = 2;
    return true;
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
    bool flag = true;
    for(int i = 1; i <= n && flag == true; i++)
        if(!visited[i])
            flag &= dfs(i);

    if(!flag)
        cout << "Graph is not a DAG";
    else
    {
        for(int i = n - 1; i >= 0; i--)
            cout << result[i] << " ";
    }
}