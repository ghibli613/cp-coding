#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

struct SegmentTree
{
    int n; // segment tree on [1, n]
    vector<long long> f;

    SegmentTree() = default;
    SegmentTree(int _n)
    {
        n = _n;
        f.assign(n * 4 + 1, 0);
    }

    void update(int id, int l, int r, int u, long long val)
    {
        if (l > u || r < u) return;
        if (l == r)
        {
            f[id] = val;
            return;
        }
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, val);
        update(id * 2 + 1, mid + 1, r, u, val);
        f[id] = f[id * 2] ^ f[id * 2 + 1];
    }

    void update(int u, long long val)
    {
        update(1, 1, n, u, val);
    }

    long long get(int id, int l, int r, int u, int v)
    {
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) return f[id];

        int mid = (l + r) / 2;

        return get(id * 2, l, mid, u, v) ^ get(id * 2 + 1, mid + 1, r, u, v);
    }

    long long get(int u, int v)
    {
        if (u > v) return 0;
        return get(1, 1, n, u, v);
    }
};

int n, sz[N], chain[N], par[N], depth[N], nbase = 0, pos[N];
vector<int> g[N];
SegmentTree seg;
long long expectedSum[N], expectedXor[N];
long long a[N], val[N];
map<long long, bool> used;
mt19937 rng(48201);

long long getRand()
{
    long long x;
    while(1)
    {
        x = uniform_int_distribution<long long> (1, LLONG_MAX)(rng);
        if(!used[x]) {
            used[x] = true;
            return x;
        }
    }
}

void dfs(int u)
{
    sz[u] = 1;
    int mx = -1;
    for (int i = 0; i < (int)g[u].size(); i++)
    {
        int v = g[u][i];
        if (v == par[u]) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
        sz[u] += sz[v];
        if (mx == -1 || sz[v] > sz[g[u][mx]]) mx = i;
    }
    if (mx > 0) swap(g[u][mx], g[u][0]);
}

void hld(int u, int c)
{
    pos[u] = ++nbase;
    chain[u] = c;
    if (par[u] == g[u][0]) return;
    hld(g[u][0], c);
    for (int i = 1; i < (int)g[u].size(); i++)
    {
        int v = g[u][i];
        if (v == par[u]) continue;
        hld(v, v);
    }
}

bool Query(int u, int v)
{
    long long Xor = 0;
    long long L = 0;
    while (chain[v] != chain[u])
    {
        if (depth[chain[u]] < depth[chain[v]])
        {
            Xor ^= seg.get(pos[chain[v]], pos[v]);
            L += pos[v] - pos[chain[v]] + 1;
            
            v = par[chain[v]];
        }
        else
        {
            Xor ^= seg.get(pos[chain[u]], pos[u]);
            L += pos[u] - pos[chain[u]] + 1;
            
            u = par[chain[u]];
        }
    }
 
    if (depth[v] > depth[u])
    {
        Xor ^= seg.get(pos[u], pos[v]);
        L += pos[v] - pos[u] + 1;
    }
    else
    {
        Xor ^= seg.get(pos[v], pos[u]);
        L += pos[u] - pos[v] + 1;
    }

    return Xor == expectedXor[L];
}

void solve()
{
    int Q;
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    hld(1, 1);
    
    seg = SegmentTree(n);
    for (int u = 1; u <= n; u++)
    {
        seg.update(pos[u], val[a[u]]);
    }
    int cnt = 0;
    while (Q--)
    {
        int type, u, v;
        cin >> type >> u >> v;
        cnt++;
        if (type == 1)
        {
            if (Query(u, v))
            {
                cout << "Yes\n";
            }
            else cout << "No\n";
        }
        else
        {
            seg.update(pos[u], val[v]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        par[i] = 0;
    }
    nbase = 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    srand(time(NULL));
    for (int i = 1; i < N; i++)
        val[i] = getRand();
    
    expectedXor[0] = 0;
    for (int i = 1; i < N; i++)
        expectedXor[i] = expectedXor[i - 1] ^ val[i];

    int nTest;
    cin >> nTest;
    while (nTest--)
    {
        solve();
    }
    return 0;
}