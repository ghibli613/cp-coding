const int MAX = 1010;
const ll INF = 1e18;

struct Edge
{
    int u, v;
    ll cap, cost;
    Edge(int u = 0, int v = 0, ll cap = 0, ll cost = 0)
        : u(u), v(v), cap(cap), cost(cost) {}
};

vector<Edge> edges;
ll dist[MAX];
int pre[MAX];
vector<int> graph[MAX];
int n, m;

void addEdge(int u, int v, ll cap, ll cost)
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
    dist[s] = 0; inQueue[s] = true; q.push(s);
    
    while(!q.empty())
    {
        int u = q.front(); q.pop(); inQueue[u] = false;
        for(int id : graph[u])
        {
            int v = edges[id].v;
            ll cap = edges[id].cap, cost = edges[id].cost;
            if(cap <= 0 || dist[v] <= dist[u] + cost) continue;
            dist[v] = dist[u] + cost;
            pre[v] = id;
            if(!inQueue[v])
            {
                q.push(v); inQueue[v] = true;
            }
        }
    }
    return dist[t] != INF;
}

pair<ll, ll> mcmf(int s, int t)
{
    ll minCost = 0, maxFlow = 0;
    while (spfa(s, t))
    {
        ll flow = INF;
        int id, cur = t;
        while(cur != s)
        {
            id = pre[cur];
            flow = min(flow, edges[id].cap);
            cur = edges[id].u;
        }
        maxFlow += flow;
        minCost += flow * dist[t];
        cur = t;
        while(cur != s)
        {
            id = pre[cur];
            edges[id].cap -= flow;
            edges[id ^ 1].cap += flow;
            cur = edges[id].u;
        }
    }
    
    return {minCost, maxFlow};
}

void test()
{
    int s, t;
    cin >> n >> m >> s >> t;
    for(int u, v, cap, cost, i = 0; i < m; i++)
    {
        cin >> u >> v >> cap >> cost;
        addEdge(u, v, cap, cost);
    }
    pair<ll, ll> res = mcmf(s, t);
    cout << res.second << " " << res.first << "\n";
}