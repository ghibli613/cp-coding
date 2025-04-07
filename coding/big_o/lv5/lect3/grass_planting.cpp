#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

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
        seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
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
        seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
    }

    T lazySumQuery(int id, int l, int r, int fr, int to)
    {
        if (lazy[id] != 0)
            down(id, l, r);
        if (fr > r || to < l)
            return 0;
        if (fr <= l && r <= to)
            return seg[id];

        int m = (l + r) / 2;

        return lazySumQuery(2 * id + 1, l, m, fr, to) + lazySumQuery(2 * id + 2, m + 1, r, fr, to);
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
    long long res = 0;

    while (true)
    {
        if (in[u] > in[v])
            swap(u, v);
        if (top[u] == top[v])
            break;
        res += f.lazySumQuery(0, 0, n - 1, in[top[v]], in[v]);
        v = parent[top[v]];
    }
    return res + f.lazySumQuery(0, 0, n - 1, in[u] + 1, in[v]);
}

void queryUpdate(int u, int v)
{
    while (true)
    {
        if (in[u] > in[v])
            swap(u, v);
        if (top[u] == top[v])
            break;
        f.lazyUpdate(0, 0, n - 1, in[top[v]], in[v], 1);
        v = parent[top[v]];
    }
    f.lazyUpdate(0, 0, n - 1, in[u] + 1, in[v], 1);
}

void solve()
{
    int q;
    cin >> n >> q;
    // vector<int> a(n + 1);
    // for (int i = 1; i <= n; i++)
    //     cin >> a[i];

    graph.resize(n + 1);
    for (int u, v, i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    hld(1);

    /* cach 1: cap nhap tung phan tu
    for (int i = 0; i < n; i++)
        update(in[i], a[i]);
    */
    // cach 2: build tree
    // vector<long long> temp(n);
    // for (int i = 1; i <= n; i++)
    //     temp[in[i]] = a[i];
    f = LazySegTree<ll>(n);

    while (q--)
    {
        char t;
        int u, v;
        cin >> t >> u >> v;
        if (t == 'P')
            queryUpdate(u, v);
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