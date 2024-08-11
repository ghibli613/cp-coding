#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<int, int> pii;
vector<vector<pii>> adj;
vector<int> dist;
vector<pii> res;

void dijkstra(int s, int n)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty())
    {
        pii tmp = pq.top(); pq.pop();

        int u = tmp.second;
        if(tmp.first != dist[u]) continue;

        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    int max_dis = 0, num_cities = 0;
    for(int i = 0; i < n; i++)
    {
        if(dist[i] != (int)1e9 && dist[i] > max_dis)
        {
            max_dis = dist[i];
            num_cities = 1;
        }
        else if(dist[i] == max_dis)
        {
            num_cities++;
        }
    }
    res[s].first = max_dis; res[s].second = num_cities;
}

void solve()
{
    int n, m, q; cin >> n >> m >> q;
    adj.assign(n, vector<pii>());
    res = vector<pii>(n, {-1, -1});
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    while(q--)
    {
        int s; cin >> s;
        dist = vector<int>(n, (int)1e9);
        if(res[s].first == -1)
        {
            dijkstra(s, n);
            cout << res[s].first << ' ' << res[s].second << '\n';
        }
        else
        {
            cout << res[s].first << ' ' << res[s].second << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}