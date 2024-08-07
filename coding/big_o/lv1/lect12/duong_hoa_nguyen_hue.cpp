#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> graph;
vector<bool> visited;
bool mark = false, mark2 = false;

void checkCycle(int vertex, int parent)
{
    visited[vertex] = true;
    if(graph[vertex].size() > 2)
    {
        mark = true;
    }
    for(int i = 0; i < (int)graph[vertex].size(); i++)
    {
        if(!visited[graph[vertex][i]])
        {
            checkCycle(graph[vertex][i], vertex);
        }
        else if(graph[vertex][i] != parent) mark2 = true;
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    graph.assign(n, vector<int>());
    visited.assign(n, false);

    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    int ans = 0, ans1 = 0;
    for(int i = 0; i < n; i++)
    {
        if(visited[i]) continue;
        else
        {
            mark = false; mark2 = false;
            checkCycle(i, -1);
            
            if(mark2 == false) ans++; 
            else if(!mark) ans1++;
        }
    }
    cout << ans << ' ' << ans1 << '\n';
    // cout << checkCycle(2, -1);
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