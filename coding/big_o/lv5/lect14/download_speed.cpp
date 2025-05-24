#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 507;
const ll INF = 1e18;

struct Edge
{
    int u, v;
    ll cap, flow;
    Edge(int u = 0, int v = 0, ll cap = 0)
        : u(u), v(v), cap(cap), flow(0) {}
};

int level[MAX];
int iter[MAX];
vector<Edge> edges;
vector<int> graph[MAX];

void addEdge(int u, int v, ll cap)
{
    graph[u].push_back(edges.size());
    edges.push_back({u, v, cap});
    graph[v].push_back(edges.size());
    edges.push_back({v, u, 0});
}

int bfs(int s, int t)
{
    queue<int> q;
    q.push(s);
    memset(level, -1, sizeof(level));
    level[s] = 0;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i : graph[u])
        {
            if(level[edges[i].v] != -1) continue;
            if(edges[i].cap <= edges[i].flow) continue;
            level[edges[i].v] = level[u] + 1;
            q.push(edges[i].v);
        }
    }
    return level[t] != -1;
}

// find Augmenting path
ll dfs(int s, int t, ll pushed)
{
    if(pushed == 0) return 0;
    if(s == t) return pushed;
    for(int &i = iter[s]; i < (int)graph[s].size(); i++)
    {
        int id = graph[s][i];
        int v = edges[id].v;

        if(level[v] != level[s] + 1) continue;
        if(edges[id].cap <= edges[id].flow) continue;

        ll f = min(pushed, edges[id].cap - edges[id].flow);
        f = dfs(v, t, f);
        if(f == 0) continue;
        edges[id].flow += f;
        edges[id ^ 1].flow -= f;
        return f;
    }
    return 0;
}

ll dinic(int s, int t)
{
    ll newFlow, sumFlow = 0;
    while(bfs(s, t))
    {
        memset(iter, 0, sizeof(iter));
        while((newFlow = dfs(s, t, INF)))
        {
            sumFlow += newFlow;
        }
    }
    return sumFlow;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    cout << dinic(1, n);

    return 0;
}