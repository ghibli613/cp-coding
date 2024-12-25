int n;
vector<vector<int>> graph;
int block_size;
vector<int> level, parent, jump_parent;

Graph(int n_)
{
    n = n_;
    graph.assign(n + 1, vector<int>());
    level.assign(n + 1);
    parent.assign(n + 1);
    jump_parent.assign(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int getDepth(int u, int p)
{
    int res = 0;
    for(int v : graph[u])
        if(v != p)
            res = max(res, getDepth(v, u));
    return res + 1;
}

void dfs(int u, int p)
{
    level[u] = level[p] + 1;
    parent[u] = p;
    if(level[u] % block_size == 0)
        jump_parent[u] = p;
    else
        jump_parent[u] = jump_parent[p];
    
    for(int v : graph[u])
    {
        if(v != p)
            dfs(v, u);
    }
}

void preprocess()
{
    int height = getDepth(0, 1);
    block_size = sqrt(height);
    level[0] = -1;
    dfs(1, 0);
}

int lca(int u, int v)
{
    if(level[u] > level[v]) swap(u, v);
    while(level[u] < level[v])
    {
        if(level[jump_parent[v]] > level[u])
            v = jump_parent[v];
        else
            v = parent[v];
    }
    while (u != v)
    {
        if(jump_parent[u] == jump_parent[v])
        {
            u = parent[u];
            v = parent[v];
        }
        else
        {
            u = jump_parent[u];
            v = jump_parent[v];
        }
    }
    
    return u;
}
