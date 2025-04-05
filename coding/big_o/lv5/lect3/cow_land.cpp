#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

template <class T>
struct FenwickTree
{
    int n;
    vector<T> f;

    FenwickTree(int n_)
    {
        n = n_;
        f.assign(n + 7, 0);
    }

    void update(int id, int val)
    {
        while (id <= n)
        {
            f[id] ^= val;
            id += id & -id;
        }
    }

    T getSum(int id)
    {
        T sum = 0;
        while (id > 0)
        {
            sum ^= f[id];
            id -= id & -id;
        }
        return sum;
    }

    T sumRange(int l, int r)
    {
        return getSum(r) ^ getSum(l);
    }

    void updateRange(int l, int r, T val)
    {
        update(l, val);
        update(r + 1, -val);
    }
};

vector<int> parent;
vector<vector<int>> graph;
vector<int> in, out;
vector<int> top;
vector<int> order;
vector<int> sz;
int dfs_num;
int n;

FenwickTree<ll> BIT(0);

void dfs_size(int u, int p = -1)
{
    parent[u] = p;
    sz[u] = 1;
    auto it = find(graph[u].begin(), graph[u].end(), p);
    if(it != graph[u].end())
        graph[u].erase(it);
    
    for(int i = 0; i < (int)graph[u].size(); i++)
    {
        dfs_size(graph[u][i], u);
        sz[u] += sz[graph[u][i]];
        if(sz[graph[u][i]] > sz[graph[u][0]])
            swap(graph[u][i], graph[u][0]);
    }
}

void dfs_hld(int u)
{
    in[u] = ++dfs_num;
    order[dfs_num] = u;

    for(int v : graph[u])
    {
        top[v] = (v == graph[u][0]) ? top[u] : v;
        dfs_hld(v);
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

    dfs_size(root);
    top[root] = root;
    dfs_hld(root);
}

long long queryPath(int u, int v)
{
    long long res = 0;

    while(true)
    {
        if(in[u] > in[v]) swap(u, v);
        if(top[u] == top[v]) break;
        res ^= BIT.sumRange(in[top[v]], in[v] + 1);
        v = parent[top[v]];
    }
    return res ^ BIT.sumRange(in[u], in[v] + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    graph.resize(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    BIT = FenwickTree<ll>(n);
    hld(1);

    for(int i = 1; i <= n; i++)
        BIT.update(in[i] + 1, a[i - 1]);
    
    while(q--)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1)
        {
            ll tmp = BIT.sumRange(in[u], in[u] + 1);
            BIT.update(in[u] + 1, v ^ tmp);
        }
        else
            cout << queryPath(u, v) << '\n';
    }

    return 0;
}