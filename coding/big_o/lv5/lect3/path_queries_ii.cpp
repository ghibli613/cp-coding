#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

template <class T>
struct SegTree
{
    vector<T> seg;
    int n;

    SegTree(int n_)
    {
        n = n_;
        seg.assign(4 * n, 0);
    }

    SegTree(const vector<T> &a) : SegTree((int)a.size())
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

    T queryMax(int id, int l, int r, int fr, int to)
    {
        if (fr <= l && r <= to)
            return seg[id];
        if (fr > r || to < l)
            return 0;

        int m = (l + r) / 2;

        return max(
            queryMax(2 * id + 1, l, m, fr, to),
            queryMax(2 * id + 2, m + 1, r, fr, to));
    }

    void updateMax(int id, int l, int r, int pos, T val)
    {
        if (l == r)
        {
            seg[id] = val;
            return;
        }

        int m = (l + r) / 2;
        if (pos <= m)
            updateMax(2 * id + 1, l, m, pos, val);
        else
            updateMax(2 * id + 2, m + 1, r, pos, val);
        seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
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

SegTree<ll> segTree(0);

void dfs_size(int u, int p = -1)
{
    parent[u] = p;
    sz[u] = 1;
    auto it = find(graph[u].begin(), graph[u].end(), p);
    if (it != graph[u].end())
        graph[u].erase(it);

    for (int i = 0; i < (int)graph[u].size(); i++)
    {
        dfs_size(graph[u][i], u);
        sz[u] += sz[graph[u][i]];
        if (sz[graph[u][i]] > sz[graph[u][0]])
            swap(graph[u][i], graph[u][0]);
    }
}

void dfs_hld(int u)
{
    in[u] = ++dfs_num;
    order[dfs_num] = u;

    for (int v : graph[u])
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

    while (true)
    {
        if (in[u] > in[v])
            swap(u, v);
        if (top[u] == top[v])
            break;
        res = max(segTree.queryMax(0, 0, n - 1, in[top[v]], in[v]), res);
        v = parent[top[v]];
    }
    return res = max(segTree.queryMax(0, 0, n - 1, in[u], in[v]), res);
}

void solve()
{
    int q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

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
    vector<long long> temp(n);
    for (int i = 1; i <= n; i++)
        temp[in[i]] = a[i];
    segTree = SegTree<ll>(temp);
    int t, u, v;
    while (q--)
    {
        cin >> t >> u >> v;
        if (t == 1)
            segTree.updateMax(0, 0, n - 1, in[u], v);
        else
            cout << queryPath(u, v) << " ";
    }
    // cout << segTree.queryMax(0, 0, n - 1, 2, 3) << "\n";
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