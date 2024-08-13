#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
vector<vector<pii>> adj;
vector<bool> check;
int ans = 0;
int n, m, k;

bool compare(const pii &a, const pii & b)
{
    if(a.first > b.first) return true;
    else if(a.first == b.first)
    {
        if(a.second < b.second) return true;
        else return false;
    }
    else return false;
}

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, bool(*)(const pii&, const pii&)> pq(compare);
    for(int i = 0; i < k; i++)
    {
        int x, y; cin >> x >> y;
        pq.push({y, -(x - 1)});
    }
    pq.push({0, s});
    while(!pq.empty())
    {
        pii tmp = pq.top(); pq.pop();
        int u = tmp.second;
        bool valid = false;
        if(u < 0)
        {
            u = -u;
            valid = true;
        }
        if(check[u])
        {
            if(valid) ans++;
        }
        else
        {
            check[u] = true;
            for(int i = 0; i < (int)adj[u].size(); i++)
            {
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                if(check[v] == false)
                {
                    pq.push({w + tmp.first, v});
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m >> k;
    adj.assign(n, vector<pii>());
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
        adj[v - 1].push_back({u - 1, w});
    }
    check.assign(n, false);
    dijkstra(0);
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