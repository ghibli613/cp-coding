#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Graph
{
    int n, m, counter, ans;
    vector<vector<int>> graph;
    vector<bool> visited, visited1;
    stack<int> st;

    Graph()
    {
        cin >> n >> m;
        graph.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);
        visited1.assign(n + 1, false);
        for(int i = 0; i < m; i++)
        {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
        }
    }
    
    void dfs(int v)
    {
        visited[v] = true;
        for(int i = 0; i < (int)graph[v].size(); i++)
        {
            int u = graph[v][i];
            if(!visited[u]) {
                dfs(u);
            }
        }
    }
    
    void dfs2(int v)
    {
        visited1[v] = true;
        for(int i = 0; i < (int)graph[v].size(); i++)
        {
            int u = graph[v][i];
            if(!visited1[u]) {
                visited1[u] = true;
                dfs2(u);
            }
        }
    }
    
    void solve()
    {
        for(int i = 1; i <= n; i++) 
        {
            if (!visited[i])
            {
               dfs(i);
               st.push(i);
            }
        }
        int cnt = 0;
        while (!st.empty()) 
        {
            int x = st.top();
            if (!visited1[x]){
                cnt++;
                dfs2(x);
            }
            st.pop();
        }
        cout << cnt << '\n';
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
    {
        Graph g;
        g.solve();
    }

    return 0;
}