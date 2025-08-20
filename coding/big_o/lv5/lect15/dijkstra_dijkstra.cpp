#include <bits/stdc++.h>
using namespace std;
const int MAX = 1010;
const int INF = 1e9;
struct Edge
{
    int u, v;
    int cap, cost;
    Edge(int u = 0, int v = 0, int cap = 0, int cost = 0) : u(u), v(v), cap(cap), cost(cost) {}
};
vector<Edge> edges;
int dist[MAX];
int pre[MAX];
vector<int> graph[MAX];
int n, m;
void addEdge(int u, int v, int cap, int cost)
{
    graph[u].push_back(edges.size());
    edges.push_back({u, v, cap, cost});
    graph[v].push_back(edges.size());
    edges.push_back({v, u, 0, -cost});
}
bool spfa(int s, int t)
{
    fill(dist, dist + n + 1, INF);
    vector<bool> inQueue(n + 1, false);
    queue<int> q;
    dist[s] = 0;
    inQueue[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        inQueue[u] = false;
        for (int id : graph[u])
        {
            int v = edges[id].v;
            int cap = edges[id].cap, cost = edges[id].cost;
            if (cap <= 0 || dist[v] <= dist[u] + cost)
                continue;
            dist[v] = dist[u] + cost;
            pre[v] = id;
            if (!inQueue[v])
            {
                q.push(v);
                inQueue[v] = true;
            }
        }
    }
    return dist[t] != INF;
}
pair<int, int> mcmf(int s, int t)
{
    int minCost = 0, maxFlow = 0;
    while (spfa(s, t))
    {
        int flow = INF;
        int id, cur = t;
        while (cur != s)
        {
            id = pre[cur];
            flow = min(flow, edges[id].cap);
            cur = edges[id].u;
        }
        maxFlow += flow;
        minCost += flow * dist[t];
        cur = t;
        while (cur != s)
        {
            id = pre[cur];
            edges[id].cap -= flow;
            edges[id ^ 1].cap += flow;
            cur = edges[id].u;
        }
    }
    return {minCost, maxFlow};
}
int main()
{
    srand(time(NULL));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n && n)
    {
        cin >> m;
        for (int u, v, cost, i = 0; i < m; i++)
        {
            cin >> u >> v >> cost;
            addEdge(u, v, 1, cost);
            addEdge(v, u, 1, cost);
        }
        addEdge(0, 1, 2, 0);
        auto res = mcmf(0, n);
        if (res.second != 2)
        {
            cout << "Back to jail" << endl;
        }
        else
        {
            cout << res.first << endl;
        }
        for (int i = 0; i <= n; i++)
            graph[i].clear();
        edges.clear();
    }
}