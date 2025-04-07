#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

int t[N];
vector<int> parent;
vector<vector<int>> graph;
vector<int> in, out;
vector<int> top;
vector<int> order, depth;
vector<int> sz;
int dfs_num;
int n;

map<int, int> cols[N], in_cols[N];

void dfs_size(int u, int p = -1)
{
    parent[u] = p;
    sz[u] = 1;

    for(int i = 0; i < (int)graph[u].size(); i++)
    {
        if(graph[u][i] == p) continue;
        depth[graph[u][i]] = depth[u] + 1;
        dfs_size(graph[u][i], u);
        sz[u] += sz[graph[u][i]];
        if (sz[graph[u][i]] > sz[graph[u][0]])
            swap(graph[u][i], graph[u][0]);
    }
}

void dfs_hld(int u, int p = -1)
{
    in[u] = ++dfs_num;
    order[dfs_num] = u;
    if(!cols[top[u]].count(t[u]))
    {
        cols[top[u]][t[u]] = depth[u];
    }
    in_cols[t[u]][in[u]] = depth[u];
    for(int v : graph[u])
    {
        if(v == p) continue;
        top[v] = (v == graph[u][0]) ? top[u] : v;
        dfs_hld(v, u);
    }

    out[u] = dfs_num;
}

void hld(int root)
{
    dfs_num = -1;
    in.assign(n + 1, -1);
    out.assign(n + 1, -1);
    top.assign(n + 1, -1);
    parent.assign(n + 1, -1);
    sz.assign(n + 1, 0);
    order.assign(n, -1);
    depth.assign(n + 1, 0);

    dfs_size(root);
    top[root] = root;
    dfs_hld(root);
}

int getLCA(int u, int v)
{
    while(true)
    {
        if(in[u] > in[v]) swap(u, v);
        if(top[u] == top[v]) break;
        v = parent[top[v]];
    }
    return in[u] < in[v] ? u : v;
}

long long queryPath(int u, int v, int col)
{
    while (true)
    {
        if (in[u] > in[v])
            swap(u, v);
        auto it = cols[top[v]].find(col);
        if(it != cols[top[v]].end() && it->second <= depth[v])
        {
            return prev(in_cols[col].upper_bound(in[v]))->second;
        }
        if (top[u] == top[v])
            break;
        v = parent[top[v]];
    }
    return -1;
}

bool check(int u, int v, int l, int col)
{
    return queryPath(u, v, col) >= depth[l];
}

void solve()
{
    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> t[i];

    graph.resize(n + 1);
    for (int u, v, i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    hld(1);
    while(q--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        int L = getLCA(A, B);
        // cout << depth[L] << ' ';
        cout << check(A, B, L, C);
    }
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