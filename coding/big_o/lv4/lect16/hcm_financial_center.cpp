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

int get_dob_path(vector<int> x)
{
    int lca_xy = lca(x[0], x[1]);
    int lca_yz = lca(lca_xy, x[2]);
    if(lca_yz != lca_xy) return dist(lca_xy, x[2]);
    else
    {
        lca_yz = lca(x[1], x[2]);
        if(lca_yz != lca_xy) return dist(lca_yz, x[1]);
        else
        {
            int lca_xz = lca(x[0], x[1]);
            return dist(lca_xz, x[1]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        g[i].push_back(u);
        g[u].push_back(i);
    }

    dfs(1);

    for (int i = 0; i < q; i++)
    {
        vector<int> x(3);
        cin >> x[0] >> x[1] >> x[2];
        int ans = 0;
        sort(x.begin(), x.end());
        do
        {
            ans = max(ans, get_dob_path(x));
        } while (next_permutation(x.begin(), x.end()));
        cout << ans + 1 << '\n';
    }

    return 0;
}