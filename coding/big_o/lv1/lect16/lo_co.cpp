#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<bool> visited;
vector<vector<int>> graph;
vector<int> result;

void topo(int u)
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (visited[v] == false)
            topo(v);
    }
    result.push_back(u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }
    sort(a.begin(), a.end());
    visited.assign(n, 0);
    graph.assign(n, vector<int>());

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int s = a[i] + a[j];
            int idx = lower_bound(a.begin(), a.end(), s) - a.begin();
            if (a[idx] == s)
            {
                graph[mp[a[i]]].push_back(mp[s]);
                graph[mp[a[j]]].push_back(mp[s]);
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (visited[i] == false)
            topo(i);

    vector<int> dist(n, 1);
    for (int i = (int)result.size() - 1; i >= 0; i--)
    {
        int u = result[i];
        for (int v : graph[u])
        {
            dist[v] = max(dist[v], dist[u] + 1);
        }
    }
    int ret = dist[0];
    for (int i = 1; i < n; i++)
    {
        ret = max(ret, dist[i]);
    }
    cout << ret << '\n';

    return 0;
}