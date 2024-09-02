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
    int ans = 0;
    
    Graph(int n = 0, int m = 0):
        adj(n, vector<pii>()),
        dist(n, MOD),
        visited(n, false)
        {
            for(int i = 0; i < m; i++)
            {
                int x, y, z;
                cin >> x >> y >> z;
                adj[x].push_back({y, z});
                adj[y].push_back({x, z});
                ans += z;
            }
        }
    
    int prim()
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        int cnt = 0;
    
        while(!pq.empty())
        {
            pii tmp = pq.top(); pq.pop();
            int u = tmp.second;
            if(visited[u]) continue;
            visited[u] = true;
            cnt += tmp.first;
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
        return ans - cnt;
    }
};

void solve(int n, int m)
{
    Graph g(n, m);
    cout << g.prim() << '\n';
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