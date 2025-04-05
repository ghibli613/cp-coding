vector<int> parent;
vector<vector<int>> graph;
vector<int> in, out;
vector<int> top;
vector<int> order;
vector<int> sz;
int dfs_num;
int n;

void dfs_size(int u, int p = -1)
{
    parent[u] = p;
    sz[u] = 1;
    auto it = find(graph[u].begin(), graph[u].end(), p);
    if (it != graph[u].end())
        graph[u].erase(it);

    for (int i = 0; i < (int)graph[u].size(); i++)
    {
        dfs_size(graph[u][i], u);
        sz[u] += sz[graph[u][i]];
        if (sz[graph[u][i]] > sz[graph[u][0]])
            swap(graph[u][i], graph[u][0]);
    }
}

void dfs_hld(int u)
{
    in[u] = ++dfs_num;
    order[dfs_num] = u;

    for (int v : graph[u])
    {
        top[v] = (v == graph[u][0]) ? top[u] : v;
        dfs_hld(v);
    }

    out[u] = dfs_num;
}

void hld(int root)
{
    dfs_num = -1;
    in.assign(n + 1, -1);
    out.assign(n + 1, -1);
    top.assign(n + 1, -1);
    parent.assign(n + 1, -1);
    sz.assign(n + 1, 0);
    order.assign(n, -1);

    dfs_size(root);
    top[root] = root;
    dfs_hld(root);
}

long long queryPath(int u, int v)
{
    long long res = 0;

    while (true)
    {
        if (in[u] > in[v])
            swap(u, v);
        if (top[u] == top[v])
            break;
        res += query(in[top[v]], in[v]);
        v = parent[top[v]];
    }
    return res + query(in[u], in[v]);
}

void tes()
{
    int q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    graph.resize(n + 1);
    for (int u, v, i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    hld(1);

    /* cach 1: cap nhap tung phan tu
    for (int i = 0; i < n; i++)
        update(in[i], a[i]);
    */
    // cach 2: build tree
    vector<long long> temp(n);
    for (int i = 0; i < n; i++)
        temp[in[i]] = a[i];
    buildTree(temp);
    int t, u, v;
    while (q--)
    {
        cin >> t >> u >> v;
        if (t == 1)
            update(in[u], a[u] += v);
        else
            cout << queryPath(u, v) << "\n";
    }

}