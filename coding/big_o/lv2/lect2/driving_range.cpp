#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Graph
{
    vector<vector<pii>> adj;
    vector<int> dist;
    vector<bool> visited;

    Graph(int n = 0, int m = 0):
        adj(n, vector<pii>()),
        dist(n, MOD),
        visited(n, false)
        {
            for(int i = 0; i < m; i++)
            {
                int u, v, w;
                cin >> u >> v >> w;
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
        }

    int prim()
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        dist[0] = 0;
    
        int count = 0;
        while(!pq.empty())
        {
            pii tmp = pq.top(); pq.pop();
            int u = tmp.second;
            if(visited[u]) continue;
            visited[u] = true;
            if(tmp.first > count) count = tmp.first;
            for(int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                if(!visited[v] && dist[v] > w)
                {
                    dist[v] = w;
                    pq.push({w, v});
                }
            }
        }
        return count;
    }
};

void solve(int n, int m)
{
    Graph g(n, m);
    int ans = g.prim();
    if(ans == 0) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while(true)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        solve(n, m);
    }

    return 0;
}