#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

vector<vector<int>> graph, pre;
vector<bool> visited;
vector<int> topo;

void dfs_topo(int u)
{
    visited[u] = true;
    for(int i = 0; i < (int)graph[u].size(); i++)
    {
        if(!visited[graph[u][i]])
            dfs_topo(graph[u][i]);
    }
    topo.push_back(u);
}

void solve()
{
    int n, m; cin >> n >> m;
    graph.assign(n + 1, vector<int>());
    pre.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        pre[v].push_back(u);
    }

    dfs_topo(1);
    reverse(topo.begin(), topo.end());

    if(!visited[n])
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> f(n+1, 1);
        for(int i = 0; i < (int)topo.size(); i++)
        {
            int u = topo[i];
            for(int v : graph[u]){
                f[v] = max(f[v], f[u] + 1);
            }
        }
        cout << f[n] << '\n';

        vector<int> res;
        int dis = f[n], u = n;
        res.push_back(u);
        
        while(dis > 2)
        {
            for(int v : pre[u])
            {
                if(f[v] == dis - 1){
                    res.push_back(v);
                    dis--;
                    u = v;
                    break;
                }
            }
        }
        res.push_back(1);
        for(int i = res.size() - 1; i >= 0; i--){
            cout << res[i] << ' ';
        }
        cout << '\n';
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