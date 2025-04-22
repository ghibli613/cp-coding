const int MAX = 1e5 + 10;

ll sum[MAX];
int cnt[MAX];
vector<int> graph[MAX];
int n;

int dfs1(int u, int p = -1, int d = 0)
{
    sum[1] += d;
    cnt[u] = 1;
    for(int v : graph[u])
        if(v != p)
            cnt[u] += dfs1(v, u, d + 1);
    return cnt[u];
}

void dfs2(int u, int p = -1)
{
    for(int v : graph[u])
    {
        if(v != p)
        {
            sum[v] += sum[u] + n - 2 * cnt[v];
            dfs2(v, u);
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
    
    dfs1(1);
    dfs2(1);
    for(int i = 1; i <= n; i++)
        cout << sum[i] << " ";
}