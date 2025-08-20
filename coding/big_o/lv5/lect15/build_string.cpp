#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    // print edges
    // cout << u << " " << v << " " << cap << " " << cost << endl;
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
            ll cap = edges[id].cap, cost = edges[id].cost;
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
pair<ll, ll> mcmf(int s, int t)
{
    ll minCost = 0, maxFlow = 0;
    while (spfa(s, t))
    {
        ll flow = INF;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;
    cin >> t;
    cin >> n;

    int source = 1;
    int start1 = source + 1, start2 = start1 + n, start3 = start2 + 26;
    int sink = start3 + 26;
    n = sink;

    for (int i = start2; i < start3; i++)
    {
        addEdge(i, i + 26, MAX, 0);
    }
    int cnt[26] = {0};
    // count number of each letter in t
    for (int i = 0; i < t.size(); i++)
    {
        cnt[t[i] - 'a']++;
    }
    for (int i = start3; i < sink; i++)
    {
        if (cnt[i - start3] != 0)
            addEdge(i, sink, cnt[i - start3], 0);
    }

    for (int i = start1; i < start2; i++)
    {
        string s;
        cin >> s;
        int a;
        cin >> a;
        addEdge(source, i, a, i - start1 + 1);
        memset(cnt, 0, sizeof(cnt));
        // count the number of each letter in s
        for (int j = 0; j < s.size(); j++)
            cnt[s[j] - 'a']++;
        for (int j = 0; j < 26; j++)
            if (cnt[j] != 0)
                addEdge(i, start2 + j, cnt[j], 0);
    }
    pair<int, int> res = mcmf(source, sink);
    if (res.second == t.size())
    {
        cout << res.first << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}