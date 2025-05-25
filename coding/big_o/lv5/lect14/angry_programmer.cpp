#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 210;

struct Edge
{
    int u, v, cap, flow;
    Edge(int u, int v, int cap) : u(u), v(v), cap(cap), flow(0) {}
};

vector<Edge> edges;
vector<int> graph[MAX];
int level[MAX], iter[MAX];

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
    memset(level, -1, sizeof(level));
    level[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i : graph[u])
        {
            Edge &e = edges[i];
            if (e.cap > e.flow && level[e.v] == -1)
            {
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int u, int t, int pushed)
{
    if (u == t)
        return pushed;
    for (int &i = iter[u]; i < (int)graph[u].size(); i++)
    {
        int id = graph[u][i];
        Edge &e = edges[id];
        if (e.cap > e.flow && level[e.v] == level[u] + 1)
        {
            int f = dfs(e.v, t, min(pushed, e.cap - e.flow));
            if (f > 0)
            {
                e.flow += f;
                edges[id ^ 1].flow -= f;
                return f;
            }
        }
    }
    return 0;
}

int dinic(int s, int t)
{
    int flow = 0;
    while (bfs(s, t))
    {
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, INF)) > 0)
        {
            flow += f;
        }
    }
    return flow;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while (true)
    {
        int M, W;
        cin >> M >> W;
        if (M == 0 && W == 0)
            break;
        edges.clear();
        for (int i = 0; i < MAX; ++i)
        {
            graph[i].clear();
        }
        for (int i = 2; i <= M - 1; ++i)
        {
            int id, cost;
            cin >> id >> cost;
            addEdge(id, id + M, cost);
        }

        for (int i = 0; i < W; ++i)
        {
            int u, v, cost;
            cin >> u >> v >> cost;
            int from = (u == 1 || u == M) ? u : u + M;
            int to = v;
            addEdge(from, to, cost);
            from = (v == 1 || v == M) ? v : v + M;
            to = u;
            addEdge(from, to, cost);
        }

        cout << dinic(1, M) << '\n';
    }

    return 0;
}
