#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> adj;
vector<int> path;
vector<bool> visited;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    int u, v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            v = adj[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void solve()
{
    int n; cin >> n;
    adj.assign(n, vector<int>());
    visited.assign(n, false);
    for(int i = 0; i < n; i++)
    {
        int u; cin >> u;
        adj[u - 1].push_back(i);
        adj[i].push_back(u - 1);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(visited[i]) continue;
        bfs(i);
        ans++;
    }
    cout << ans;
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