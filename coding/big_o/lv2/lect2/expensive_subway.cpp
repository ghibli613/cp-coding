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

    Graph(int n = 0):
        adj(n, vector<pii>()),
        dist(n, MOD),
        visited(n, false)
        {}

    
    int prim(int s)
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, s});
        dist[s] = 0;
    
        int count = 0;
        while(!pq.empty())
        {
            pii tmp = pq.top(); pq.pop();
            int u = tmp.second;
            if(visited[u]) continue;
            visited[u] = true;
            count += tmp.first;
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
        for(int i = 0; i < (int)visited.size(); i++)
            if(!visited[i]) return -1;
        return count;
    }
};

void solve(int n, int m)
{
    map<string, int> mm;
    for(int i = 0; i < n; i++)
    {
        string tmp; cin >> tmp;
        mm[tmp] = i;
    }

    Graph g(n);

    for(int i = 0; i < m; i++)
    {
        string u, v; int w;
        cin >> u >> v >> w;
        g.adj[mm[u]].push_back({mm[v], w});
        g.adj[mm[v]].push_back({mm[u], w});
    }

    string s; cin >> s;
    int ans = g.prim(mm[s]);
    if(ans == -1) cout << "Impossible\n";
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