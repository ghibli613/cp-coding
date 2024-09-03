#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Graph
{
    vector<vector<int>> graph;
    vector<int> result;
    vector<int> indegree;
    int n;

    Graph(int n = 0, int m = 0):
        graph(n + 1, vector<int>()),
        indegree(n + 1, 0),
        n(n)
        {
            for(int i = 0; i < m; i++)
            {
                int u, v;
                cin >> u >> v;
                graph[u].push_back(v);
                indegree[v]++;
            }
        }
    
    
    int kahn()
    {
        queue<int> q;
        for(int i = 1; i <= n; i++)
            if(indegree[i] == 0)
                q.push(i);
        bool flag = false;
        while(!q.empty())
        {
            if(q.size() > 1) flag = true;
            int u = q.front(); q.pop();
            result.push_back(u);
            for(int i = 0; i < (int)graph[u].size(); i++)
            {
                indegree[graph[u][i]]--;
                if(indegree[graph[u][i]] == 0)
                {
                    q.push(graph[u][i]);
                }
            }
        }
        if((int)result.size() != n) return 0;
        else 
        {
            if(flag) return 1;
            else return 2;
        }
    }

    void out()
    {
        for(int i = 0; i < n; i++)
            cout << result[i] << ' ';
        cout << '\n';
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    Graph g(n, m);
    int ans = g.kahn();
    if(ans == 0) cout << "recheck hints\n";
    else if(ans == 1) cout << "missing hints\n";
    else g.out();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}