#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 1e9;

int n, m;
vector<vector<pii>> graph;
vector<vector<int>> dist;

int dijkstra(int s, int t)
{
    dist.assign(n + 1, vector<int>(2, INF));
    dist[s][0] = 0;
    dist[s][1] = 0;
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push(piii(0, pii(s, 0)));
    pq.push(piii(0, pii(s, 1)));

    while (!pq.empty())
    {
        int u = pq.top().second.first;
        int dir = pq.top().second.second;
        int du = pq.top().first;
        pq.pop();
        if (dist[u][dir] != du)
            continue;

        for (int i = 0; i < (int)graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int _dir = graph[u][i].second;
            int ndist = du;
            if (dir != _dir)
                ndist++;
            if (dist[v][_dir] > ndist)
            {
                dist[v][_dir] = ndist;
                pq.push(piii(ndist, pii(v, _dir)));
            }
        }
    }
    return min(dist[t][0], dist[t][1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    graph.assign(n + 1, vector<pii>());

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(pii(v, 0));
        graph[v].push_back(pii(u, 1));
    }

    int s, t;
    cin >> s >> t;
    cout << dijkstra(s, t);

    return 0;
}