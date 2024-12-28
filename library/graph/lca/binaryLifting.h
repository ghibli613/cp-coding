int n, level;
vector<vector<int>> graph;
int counter;
vector<int> tin, tout;
vector<vector<int>> parent;

void dfs(int u, int p)
{
    tin[u] = ++counter;
    
    parent[u][0] = p;
    for(int v : graph[u])
        if(v != p)
            dfs(v, u);
    
    tout[u] = ++counter;
}

void preprocess(int root)
{
    counter = 0;
    dfs(root, root);

    for(int k = 1; k < level; k++)
        for(int i = 1; i <= n; i++)
            parent[i][k] = parent[parent[i][k - 1]][k - 1];
}

int isAncestor(int u, int v)
{
    return tin[u] <= tin[v] && tin[v] <= tout[u];
}

int lca(int u, int v)
{
    if(isAncestor(u, v)) return u;
    if(isAncestor(v, u)) return v;

    for(int k = level - 1; k >= 0; k--)
        if(!isAncestor(parent[u][k], v))
            u = parent[u][k];
    
    return parent[u][0];
}

void test()
{
    int q, u, v;
    cin >> n;
    graph.assign(n + 1, vector<int>());
    tin.assign(n + 1, 0); tout.assign(n + 1, 0);

    level = ceil(log2(n));
    parent.assign(n + 1, vector<int>(level));

    for(int i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    preprocess();
    cin >> q;
    while(q--)
    {
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
}