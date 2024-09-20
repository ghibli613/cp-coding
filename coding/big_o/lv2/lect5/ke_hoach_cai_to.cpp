#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Graph
{
    int n, m, counter, bridge;
    vector<vector<int>> graph;
    vector<int> num, low, sz;
    ll sum;

    Graph()
    {
        cin >> n >> m;
        graph.assign(n + 1, vector<int>());
        num.assign(n + 1, 0); low.assign(n + 1, 0);
        sz.assign(n + 1, 0);
        counter = 0; bridge = 0; sum = 0;
        
        for(int i = 0; i < m; i++)
        {
            int u, v; cin >> u >> v; 
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    
    void dfs_bridge_cut_vertex(int u, int p)
    {
        counter++;
        num[u] = low[u] = counter;
        sz[u] = 1;
    
        for(int v : graph[u])
        {
            if(v == p) continue;
            if(num[v] > 0)
                low[u] = min(low[u], num[v]);
            else
            {
                dfs_bridge_cut_vertex(v, u);
                low[u] = min(low[u], low[v]);
                
                sz[u] += sz[v];
                if(low[v] > num[u])
                {
                    bridge++;
                    sum += 1ll * sz[v] * (n - sz[v]) - 1;
                }
            }
        }
    }
    
    void solve()
    {
        int cntCmp = 0;
        for(int i = 1; i < n; i ++)
        {
            if(num[i] == 0)
            {
                cntCmp++;
                dfs_bridge_cut_vertex(i, -1);
            }
        }
        if(cntCmp == 1)
        {
            cout << sum + 1ll * (m - bridge) * (n * (n - 1) / 2 - m);
        }
        else if(cntCmp == 2)
            cout << 1ll * (m - bridge) * sz[1] * (n - sz[1]);
        else if(cntCmp >= 3)
            cout << 0;
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    g.solve();

    return 0;
}