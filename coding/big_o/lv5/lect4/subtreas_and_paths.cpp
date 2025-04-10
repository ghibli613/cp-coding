#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

vector<int> parent;
vector<vector<int>> graph;
vector<int> in, out;
vector<int> top;
vector<int> order;
vector<int> sz;
int dfs_num;
int n;

template <class T>
struct LazySegTree
{
    vector<T> seg, lazy;
    int n;

    LazySegTree(int n_)
    {
        n = n_;
        seg.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    LazySegTree(const vector<T> &a) : LazySegTree((int)a.size())
    {
        buildTree(a, 0, 0, n - 1);
    }

    void buildTree(const vector<T> &a, int id, int l, int r)
    {
        if (l == r)
        {
            seg[id] = a[l];
            return;
        }
        int m = (l + r) / 2;
        buildTree(a, 2 * id + 1, l, m);
        buildTree(a, 2 * id + 2, m + 1, r);
        seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
    }

    void down(int id, int l, int r)
    {
        if (l != r)
        {
            lazy[2 * id + 1] += lazy[id];
            lazy[2 * id + 2] += lazy[id];
        }
        seg[id] += lazy[id];
        lazy[id] = 0;
    }

    void lazyUpdate(int id, int l, int r, int fr, int to, T val)
    {
        if (lazy[id] != 0)
            down(id, l, r);
        if (fr > r || to < l)
            return;
        if (fr <= l && r <= to)
        {
            seg[id] += val;
            if (l != r)
            {
                lazy[2 * id + 1] += val;
                lazy[2 * id + 2] += val;
            }
            return;
        }
        int m = (l + r) / 2;
        lazyUpdate(2 * id + 1, l, m, fr, to, val);
        lazyUpdate(2 * id + 2, m + 1, r, fr, to, val);
        seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
    }

    T lazyMaxQuery(int id, int l, int r, int fr, int to)
    {
        if (lazy[id] != 0)
            down(id, l, r);
        if (fr > r || to < l)
            return LLONG_MIN;
        if (fr <= l && r <= to)
            return seg[id];

        int m = (l + r) / 2;

        return max(
            lazyMaxQuery(2 * id + 1, l, m, fr, to),
            lazyMaxQuery(2 * id + 2, m + 1, r, fr, to));
    }
};

LazySegTree<ll> f(0);

void dfs_size(int u, int p = -1)
{
    parent[u] = p;
    sz[u] = 1;

    for(int i = 0; i < (int)graph[u].size(); i++)
    {
        if(graph[u][i] == p) continue;
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

    dfs_size(root);
    top[root] = root;
    dfs_hld(root);
}

long long queryPath(int u, int v)
{
    long long res = LLONG_MIN;

    while (true)
    {
        if (in[u] > in[v])
            swap(u, v);
        if (top[u] == top[v])
            break;
        res = max(f.lazyMaxQuery(0, 0, n - 1, in[top[v]], in[v]), res);
        v = parent[top[v]];
    }
    return res = max(f.lazyMaxQuery(0, 0, n - 1, in[u], in[v]), res);
}

void solve()
{
    int q;
    cin >> n;

    graph.resize(n + 1);
    for (int u, v, i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    hld(1);

    f = LazySegTree<ll>(n);
    cin >> q;
    string t; 
    int u, v;
    while (q--)
    {
        cin >> t >> u >> v;
        if (t == "add")
        {
            f.lazyUpdate(0, 0, n - 1, in[u], out[u], v);
        }
        else
            cout << queryPath(u, v) << "\n";
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