#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Graph
{
    int n, m, cnt, ans; 
    vector<vector<int>> graph;
    vector<bool> visited;

    Graph()
    {
        cin >> n >> m;
        graph.assign(n + 1, vector<int>());

        for(int i = 0; i < m; i++)
        {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    
    void findHamiltonPath(int u)
    {
        ans = max(ans, cnt);
        for(int v : graph[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                cnt++;
                findHamiltonPath(v);
                cnt--;
                visited[v] = false;
            }
        }
    }
    
    void solve()
    {
        for(int i = 1; i <= n; i++)
        {
            visited.assign(n + 1, false);
            cnt = ans = 0;
            findHamiltonPath(i);
            if(ans == n)
            { 
                cout << "YES\n";
                return;
            }
        }
        
        cout << "NO\n";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
    {
        Graph g;
        g.solve();
    }

    return 0;
}