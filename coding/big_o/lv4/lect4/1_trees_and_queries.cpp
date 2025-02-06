#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 9;

int h[N], up[N][20];
vector<int> g[N];

void dfs(int u)
{
    for (int v : g[u])
    {
        if (v == up[u][0])
            continue;
        h[v] = h[u] + 1;

        up[v][0] = u;
        for (int j = 1; j < 20; ++j)
            up[v][j] = up[up[v][j - 1]][j - 1];

        dfs(v);
    }
}

int lca(int u, int v)
{
    if (h[u] != h[v])
    {
        if (h[u] < h[v])
            swap(u, v);

        // Tìm tổ tiên u' của u sao cho h(u') = h(v)
        int k = h[u] - h[v];
        for (int j = 0; (1 << j) <= k; ++j)
            if (k >> j & 1) // Nếu bit thứ j của k là 1
                u = up[u][j];
    }
    if (u == v)
        return u;

    // Tìm lca(u, v)
    int k = __lg(h[u]);
    for (int j = k; j >= 0; --j)
        if (up[u][j] != up[v][j]) // Nếu tổ tiên thứ 2^j của u và v khác nhau
            u = up[u][j], v = up[v][j];
    return up[u][0];
}

int dist(int u, int v)
{
    int lca_u_v = lca(u, v);
    return h[u] + h[v] - 2 * h[lca_u_v];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int without = dist(a, b);
        int with = min(dist(a, x) + dist(y, b), dist(a, y) + dist(x, b)) + 1;
        int ans = 1e9 + 7;
        if (without % 2 == k % 2)
            ans = without;
        if (with % 2 == k % 2)
            ans = min(ans, with);
        cout << (ans <= k ? "YES" : "NO") << '\n';
    }

    return 0;
}