#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Graph
{
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<int> result;
    int n, m;

    Graph(int n = 0, int m = 0) : graph(n + 1, vector<int>()),
                                  visited(n + 1, false), n(n), m(m)
    {
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
        }
    }

    void dfs_topo(int u)
    {
        visited[u] = true;
        for (int i = 0; i < (int)graph[u].size(); i++)
        {
            if (!visited[graph[u][i]])
                dfs_topo(graph[u][i]);
        }
        result.push_back(u);
    }

    bool isCyclic()
    {

        // stores in-degree of each vertex
        vector<int> inDegree(n + 1, 0);
        inDegree[0] = -1;

        // queue to store vertices with 0 in-degree
        queue<int> q;

        int num_visited = 0; // count of visited vertices

        // Calculate in-degree of each vertex
        for (int u = 1; u <= n; u++)
        {
            for (auto v : graph[u])
            {
                inDegree[v]++;
            }
        }

        // Enqueue vertices with 0 in-degree
        for (int u = 1; u <= n; u++)
        {
            if (inDegree[u] == 0)
            {
                q.push(u);
            }
        }

        // BFS traversal
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            num_visited++;

            // Reduce in-degree of adjacent vertices
            for (auto v : graph[u])
            {
                inDegree[v]--;

                // If in-degree becomes 0, enqueue it
                if (inDegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        // If not all vertices are visited, cycle
        return num_visited != n;
    }

    void calculate()
    {
        if(isCyclic())
        {
            cout << "IMPOSSIBLE";
            return;
        }
        for (int i = 1; i <= n; i++)
            if (!visited[i])
                dfs_topo(i);
        for (int i = n - 1; i >= 0; i--)
            cout << result[i] << ' ';
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
    g.calculate();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}