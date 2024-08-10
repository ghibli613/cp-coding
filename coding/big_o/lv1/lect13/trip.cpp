#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<vector<pii>> adj;
vector<int> d;

bool dijkstra(int x, int n)
{
    d.assign(n, 1e9);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[0] = 0;
    pq.push({0, 0});
    d[0] = 0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if(du != d[u]) continue;
        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int dv = adj[u][i].second;
            if(d[v] > d[u] + (dv > x))
            {
                d[v] = d[u] + (dv > x);
                pq.push({d[v], v});
            }
        }
    }
    return d[n - 1] <= 1;
}

void solve()
{
    int n, m; cin >> n >> m;
    adj.assign(n, vector<pii>());
    
    int u, v, w;
    int l = 0, r = 0, res = -1;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        if(w > r) r = w;
        adj[u - 1].push_back({v - 1, w});
        adj[v - 1].push_back({u - 1, w});
    }
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(dijkstra(mid, n))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << res;
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