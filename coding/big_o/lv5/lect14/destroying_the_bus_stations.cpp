#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 207;
const int INF = 1e9;

struct Edge
{
    int u, v, cap, flow;
    Edge(int u = 0, int v = 0, int cap = 0) : u(u), v(v), cap(cap), flow(0) {}
};

int n, m, k;
int level[MAX];
int iter[MAX];
vector<Edge> edges;
vector<int> graph[MAX];

void addEdge(int u, int v, int cap)
{
    graph[u].push_back(edges.size());
    edges.push_back({u, v, cap});
    graph[v].push_back(edges.size());
    edges.push_back({v, u, 0});
}

bool bfs(int s, int t)
{
    queue<int> q;
    q.push(s);
    memset(level, -1, sizeof(level));
    level[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i : graph[u])
        {
            if (level[edges[i].v] != -1)
                continue;
            if (edges[i].cap <= edges[i].flow)
                continue;
            level[edges[i].v] = level[u] + 1;
            q.push(edges[i].v);
        }
    }
    return level[t] != -1;
}

int dfs(int s, int t, int pushed)
{
    if (pushed == 0)
        return 0;
    if (s == t)
        return pushed;
    for (int &i = iter[s]; i < graph[s].size(); i++)
    {
        int id = graph[s][i];
        int v = edges[id].v;

        if (level[v] != level[s] + 1)
            continue;
        if (edges[id].cap <= edges[id].flow)
            continue;

        int f = min(pushed, edges[id].cap - edges[id].flow);
        f = dfs(v, t, f);
        if (f == 0)
            continue;
        edges[id].flow += f;
        edges[id ^ 1].flow -= f;
        return f;
    }
    return 0;
}

long long dinic(int s, int t)
{
    long long newFlow, sumFlow = 0;
    while (bfs(s, t))
    {
        memset(iter, 0, sizeof(iter));
        while (newFlow = dfs(s, t, INF))
        {
            sumFlow += newFlow;
        }
    }
    return sumFlow;
}

void BFS(int s, vector<vector<int>> &graph, vector<int> &d)
{
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
        {
            if (d[v] != -1)
                continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m >> k && n)
    {
        vector<vector<int>> graph1(n, vector<int>());
        vector<vector<int>> graph2(n, vector<int>());
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            graph1[a - 1].push_back(b - 1);
            graph2[b - 1].push_back(a - 1);
        }
        vector<int> d0(n, -1), d1(n, -1);
        BFS(0, graph1, d0);
        BFS(n - 1, graph2, d1);
        for (int u = 0; u < n; u++)
        {
            for (int v : graph1[u])
            {
                int d = d0[u] + d1[v];
                if (d + 1 <= k)
                {
                    addEdge(u + n, v, 1);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            addEdge(i, i + n, 1);
        }
        addEdge(0, n, 1e9);
        cout << dinic(0, n - 1) << endl;
        for (int i = 0; i < 2 * n; i++)
        {
            graph[i].clear();
        }
        edges.clear();
    }
}