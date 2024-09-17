#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Graph
{
    vector<bool> visited;
    vector<vector<int>> graph;
    int n, m, max_path, tmp_path;

    Graph()
    {
        cin >> n >> m;
        visited.assign(n + 1, false); 
        graph.assign(n + 1, vector<int>());
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        max_path = tmp_path = 0;
    }
    
    void findHamiltonPath(int u)
    {
        if(tmp_path > max_path)
        {
            max_path = tmp_path;
        }
    
        for(int v : graph[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                tmp_path++;
                findHamiltonPath(v);
                tmp_path--;
                visited[v] = false;
            }
        }
    }
    
    void ans()
    {
        for(int i = 1; i <= n; i++)
        {
            tmp_path = 0; max_path = 0;
            visited[i] = true;
            findHamiltonPath(i);
            visited[i] = false;
            cout << max_path << ' ';
        }
        cout << '\n';
    }
};

void solve()
{
    Graph g;
    g.ans();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}