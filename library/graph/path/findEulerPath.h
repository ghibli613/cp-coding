vector<vector<int>> deg;
int n, m;
vector<int> result;

void findEulerPath(int u)
{
    for(int v = 0; v < n; v++)
    {
        if(deg[u][v] > 0)
        {
            deg[u][v]--;
            deg[v][u]--;
            findEulerPath(v);
        }
    }
    result.push_back(u);
}

void test()
{
    cin >> n >> m;
    deg.assign(n + 1, vector<int>(n + 1, 0));

    for(int u, v, i = 0; i < m; i++)
    {
        cin >> u >> v;
        deg[u][v]++;
        deg[v][u]++;
    }

    findEulerPath(0);
    for(int v : result)
    {
        cout << v << " ";
    }
}