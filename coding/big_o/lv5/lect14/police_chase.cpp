#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 507;
const int INF = 1e9;

int cap[MAX][MAX];
int flow[MAX][MAX];
int parent[MAX];
vector<int> graph[MAX];

int bfs(int s, int t)
{
    memset(parent, -1, sizeof(parent));
    parent[s] = -2;
    queue<pair<int, int>> q;

    q.push({s, INF});
    while (!q.empty())
    {
        int u = q.front().first, f = q.front().second;
        q.pop();

        for (int v : graph[u])
        {
            if (parent[v] == -1 && cap[u][v] > flow[u][v])
            {
                parent[v] = u;
                int newFlow = min(f, cap[u][v] - flow[u][v]);
                if (v == t)
                    return newFlow;
                q.push({v, newFlow});
            }
        }
    }
    return 0;
}

int edmondsKarp(int s, int t)
{
    int newFlow, sumFlow = 0;
    while ((newFlow = bfs(s, t)) != 0)
    {
        sumFlow += newFlow;
        int prev, cur = t;
        while (cur != s)
        {
            prev = parent[cur];
            flow[prev][cur] += newFlow;
            flow[cur][prev] -= newFlow;
            cur = prev;
        }
    }
    return sumFlow;
}

bool visited[507];

void reachable()
{
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : graph[u])
        {
            if (!visited[v] && cap[u][v] > flow[u][v])
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        cap[u][v]++;
        cap[v][u]++;
    }
    edmondsKarp(1, n);
    reachable();
    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(visited[i] && !visited[j] && cap[i][j]) ans.push_back({i, j});
    
    cout << ans.size() << '\n';
    for(int i = 0; i < (int)ans.size(); i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
    return 0;
}