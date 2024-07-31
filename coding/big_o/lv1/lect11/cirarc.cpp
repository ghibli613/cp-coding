#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> graph;
vector<vector<int>> edgeCount;
vector<int> visited;
vector<int> path;
int finishV;

void dfs(int vertex, int &finishV)
{
    visited[vertex] = 1;
    for(int i = 0; i < (int)graph[vertex].size(); i++)
    {
        int v = graph[vertex][i];
        if(edgeCount[vertex][v] == 0) continue;
        if(visited[v] == 2) continue;
        path[v] = vertex;
        if(visited[v] == 1)
        {
            finishV = v;
            break;
        }
        dfs(v, finishV);
        if(finishV != -1) break;
    }
    visited[vertex] = 2;
}

vector<pair<int, int>> traceCycle()
{
    vector<pair<int, int>> res;
    int v = finishV;
    do
    {
        int u = path[v];
        res.push_back({u, v});
        v = path[v];
    } while (v != finishV);
    return res;
}

bool findCycle(int n)
{
    visited = vector<int> (n);
    finishV = -1;
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i, finishV);
            if(finishV != -1) return true;
        }
    }
    return false;
}

void solve()
{
    int n, m; cin >> n >> m;
    graph = vector<vector<int>>(n);
    edgeCount = vector<vector<int>>(n, vector<int>(n));
    path = vector<int>(n);
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        if(edgeCount[u - 1][v - 1] == 0)
        {
            graph[u - 1].push_back(v - 1);
        }
        edgeCount[u - 1][v - 1]++;
    }
    if(!findCycle(n))
    {
        cout << -1 << '\n';
        return;
    }
    vector<pair<int, int>> cycle = traceCycle();
    vector<pair<int, int>> ans;
    for(int i = 0; i < (int)cycle.size(); i++)
    {
        int u = cycle[i].first;
        int v = cycle[i].second;
        if(edgeCount[u][v] > 1) continue;
        edgeCount[u][v] = 0;
        if(!findCycle(n))
        {
            ans.push_back({u, v});
        }
        edgeCount[u][v] = 1;
    }
    if((int)ans.size() == 0)
    {
        cout << -1 << '\n';
        return;
    }
    sort(ans.begin(), ans.end());
    cout << (int)ans.size() << '\n';
    for(int i = 0; i < (int)ans.size(); i++)
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
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