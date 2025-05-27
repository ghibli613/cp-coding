#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 110;
const ll INF = 1e18;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define dbg(...) cerr<<__func__<<":"<<__LINE__<<" [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__);

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
ll d, k;

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

ll mcmf(int s, int t)
{
    ll minCost = 0, maxFlow = 0;
    bool flag = 0;
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
        if(maxFlow >= d)
        {
            flag = 1;
            minCost -= (maxFlow - d) * dist[t];
        }
        while(cur != s)
        {
            id = pre[cur];
            edges[id].cap -= flow;
            edges[id ^ 1].cap += flow;
            // edges[id ^ 1].cost = -edges[id].cost;
            cur = edges[id].u;
        }
    }
    if(flag) return minCost;
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> m)
    {
        vector<pair<pair<int, int>, ll>> tmp(m);
        for(int i = 0; i < m; i++)
        {
            cin >> tmp[i].first.first >> tmp[i].first.second >> tmp[i].second;
        }
        cin >> d >> k;
        for(int i = 0; i < m; i++)
        {
            addEdge(tmp[i].first.first, tmp[i].first.second, k, tmp[i].second);
            addEdge(tmp[i].first.second, tmp[i].first.first, k, tmp[i].second);
        }
        addEdge(0, 1, d, 0);

        ll ans = mcmf(0, n);
        if(ans == -1) cout << "Impossible.\n";
        else cout << ans << "\n";

        edges.clear();
        for(int i = 0; i < MAX; i++) graph[i].clear();
    }

    return 0;
}