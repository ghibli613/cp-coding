vector<vector<int>> graph;
vector<int> low, num;
vector<bool> isCut;
vector<pair<int, int>> bridges;
int n, m;
int counter;

void dfs(int u, int p)
{
    counter++;
    num[u] = low[u] = counter;
    int numChild = 0;

    for(int v : graph[u])
    {
        if(v == p) continue;
        if(num[v] > 0)
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            numChild++;
            if(low[v] > num[u])
                bridges.push_back(make_pair(u, v));
            if(low[v] >= num[u] && p != -1)
                isCut[u] = true;
        }
    }
    if(p == -1 && numChild > 1)
        isCut[u] = true;
}

void test()
{
    cin >> n >> m;
    graph.assign(n + 1, vector<int>());
    low.assign(n + 1, 0), num.assign(n + 1, 0);
    isCut.assign(n + 1, false);
    counter = 0;

    for(int u, v, i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!num[i])
        {
            dfs(i, -1);
        }
    }

    cout << "Bridges:\n";
    for(int i = 0; i < bridges.size(); i++)
    {
        pair<int, int> b = bridges[i];
        cout << b.first << " " << b.second << "\n";
    }
    cout << "Cut vertices:";
    for(int i = 1; i <= n; i++)
        if(isCut[i])
            cout << " " << i;
    cout << "\n";
}
