const int MAX = 1e5 + 10;

int c[MAX];
int f[MAX], g[MAX];
vector<int> graph[MAX];
int n;

void dp(int u, int p = -1)
{
    g[u] = 0;
    f[u] = c[u];
    for(int v : graph[u])
    {
        if(v != p)
        {
            dp(v, u);
            f[u] += g[v];
            g[u] += max(f[v], g[v]);
        }
    }
}

void test()
{
    cin >> n;
    for(int u, v, i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    
    dp(1);
    cout << max(f[1], g[1]) << "\n";
}