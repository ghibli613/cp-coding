#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

struct Graph
{
    int n;
    vector<vector<int>> g;
    vector<vector<int>> graph;
    vector<int> result;
    vector<bool> visited, isUse;

    Graph()
    {
        int N; cin >> N; 
        n = 0;

        vector<vector<int>> buses;
        for(int i = 0; i < N; i++)
        {
            int m; cin >> m;
            vector<int> route;
            for(int j = 0; j < m + 1; j++)
            {
                int stop; cin >> stop;
                n = max(n, stop);
                route.push_back(stop);
            }
            buses.push_back(route);
        }

        g.assign(n + 1, vector<int>(n + 1));
        graph.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);
        isUse.assign(n + 1, false);

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < (int)buses[i].size() - 1; j++)
            {
                g[buses[i][j]][buses[i][j + 1]] = 1;
                isUse[buses[i][j]] = true; 
                isUse[buses[i][j + 1]] = true;
                graph[buses[i][j]].push_back(buses[i][j + 1]);
                graph[buses[i][j + 1]].push_back(buses[i][j]);
            }
        }
    }
    
    void dfs(int s)
    {
        visited[s] = true;
    
        for(int i = 0; i < (int)graph[s].size(); i++)
        {
            int v = graph[s][i];
    
            if(!visited[v])
            {
                dfs(v);
            }
        }
    }

    bool isExistEulerPath()
    {
        int cntComp = 0;
        for(int i = 1; i <= n; i++)
            if(!visited[i] && isUse[i])
            {
                cntComp++;
                dfs(i);
            }
            
        if(cntComp > 1)
        {
            return false;
        }
        return true;
    }

    void findEulerPath(int u)
    {
        for(int v = 1; v <= n; v++)
        {
            if(g[u][v] > 0)
            {
                // cout << u << ' ' << v << '\n';
                g[u][v]--;
                findEulerPath(v);
            }
        }
        // cout << u << '\n';
        result.push_back(u);
    }
    
    void findEulerCycle()
    {
        bool check = isExistEulerPath();
        if(check)
        {
            // cout << g[2][1];
            findEulerPath(1);
            cout << result.size() - 1 << ' ';
            for(int i = (int)result.size() - 1; i >= 0 ; i--)
                cout << result[i] << ' ';
        }
        else cout << 0;
    }
    
};

void solve()
{
    Graph g;
    g.findEulerCycle();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}