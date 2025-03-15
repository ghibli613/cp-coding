#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define fi first
#define se second
#define mp make_pair

class DSU
{
public:
    int parent[MAXN];
    void init(int n)
    {
        fill(parent, parent + 1 + n, -1);
    }
    int findSet(int u)
    {
        while (parent[u] > 0)
            u = parent[u];
        return u;
    }
    bool Union(int u, int v)
    {
        int U = findSet(u);
        int V = findSet(v);
        if (U != V)
        {
            int x = parent[U] + parent[V];
            if (parent[U] > parent[V])
            {
                parent[V] = x;
                parent[U] = V;
            }
            else
            {
                parent[U] = x;
                parent[V] = U;
            }
            return 1;
        }
        return 0;
    }
} dsu;

class SCC
{
public:
    int n, m;
    int low[MAXN], num[MAXN], id_cmp[MAXN];
    bool found[MAXN];
    vector<int> G[MAXN];
    vector<int> DAG[MAXN];
    int cnt = 0, cnt_cmp = 0;
    stack<int> st;
    void DFS(int u)
    {
        num[u] = low[u] = ++cnt;
        st.push(u);
        for (int v : G[u])
        {
            if (found[v])
                continue;
            if (num[v])
                low[u] = min(low[u], num[v]);
            else
            {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
        }
        if (num[u] == low[u])
        {
            int v;
            cnt_cmp++;
            do
            {
                v = st.top();
                st.pop();
                id_cmp[v] = cnt_cmp;
                found[v] = true;
            } while (u != v);
        }
    }
    void makeDAG()
    {
        for (int i = 0; i <= cnt_cmp; i++)
            DAG[i].clear();
        for (int u = 1; u <= n; u++)
        {
            for (int v : G[u])
                if (id_cmp[u] != id_cmp[v])
                    DAG[id_cmp[u]].push_back(id_cmp[v]);
        }
    }
    void tarjan()
    {
        for (int i = 1; i <= n; i++)
            if (!num[i])
                DFS(i);
    }
    void add_edge(int u, int v)
    {
        G[u].push_back(v);
    }
    void init(int n)
    {
        this->n = n;
        while (!st.empty())
            st.pop(); // empty stack
        fill(low, low + 1 + n, 0);
        fill(num, num + 1 + n, 0);
        fill(found, found + 1 + n, 0);
        for (int i = 0; i <= n; i++)
            G[i].clear();
        m = 0;
        cnt = 0;
        cnt_cmp = 0;
    }
} scc;

class LCA
{
public:
    int R[MAXN][30];
    int n;
    int h[MAXN];
    vector<int> G[MAXN];
    void add_edge(int u, int v)
    {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    void DFS(int u, int pre)
    {
        for (int v : G[u])
            if (v != pre)
            {
                R[v][0] = u;
                h[v] = h[u] + 1;
                DFS(v, u);
            }
    }
    void init_table()
    {
        for (int j = 1; j <= log2(n); j++)
            for (int i = 1; i <= n; i++)
                R[i][j] = R[R[i][j - 1]][j - 1];
    }
    int lca(int u, int v)
    {
        if (h[u] < h[v])
            swap(u, v);
        for (int i = log2(h[u]); i >= 0; i--)
            if (h[u] - (1 << i) >= h[v])
                u = R[u][i];
        if (u == v)
            return u;
        for (int i = log2(h[u]); i >= 0; i--)
            if (R[u][i] != 0 && R[u][i] != R[v][i])
            {
                u = R[u][i];
                v = R[v][i];
            }
        return R[u][0];
    }
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i <= n; i++)
            G[i].clear();
        fill(h, h + n + 1, 0);
    }
} lca;

int f[MAXN], onCycle[MAXN], szCycle[MAXN], distCycle[MAXN];

int main()
{
    int n;
    while (cin >> n)
    {
        scc.init(n);
        dsu.init(n);
        lca.init(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> f[i];
            scc.add_edge(i, f[i]);
        }
        scc.tarjan();
        scc.makeDAG();

        int vpoint = n + 1;
        for (int i = 1; i <= n; i++)
            if (scc.DAG[scc.id_cmp[i]].size() == 0)
                lca.add_edge(vpoint, i);
            else
                lca.add_edge(i, f[i]);
        lca.DFS(vpoint, 0);
        lca.init_table();

        for (int i = 1; i <= n; i++)
        {
            if (scc.DAG[scc.id_cmp[i]].size() != 0)
                dsu.parent[i] = f[i];
            onCycle[i] = -1;
        }

        int cid = 0;
        for (int i = 1; i <= n; i++)
        {
            if (scc.DAG[scc.id_cmp[i]].size() == 0 && onCycle[i] == -1)
            {
                szCycle[cid] = 0;
                for (int u = i, d = 0; onCycle[u] == -1; u = f[u], d++, szCycle[cid]++)
                {
                    onCycle[u] = cid;
                    distCycle[u] = d;
                }
                cid++;
            }
        }

        int q;
        cin >> q;
        while (q--)
        {
            int u, v;
            cin >> u >> v;
            int cha = lca.lca(u, v);
            int dist = lca.h[u] + lca.h[v] - 2 * lca.h[cha];
            if (cha == vpoint)
            {
                int U = dsu.findSet(u);
                int V = dsu.findSet(v);
                if (onCycle[U] == onCycle[V])
                {
                    int du = distCycle[U], dv = distCycle[V];
                    if (du < dv)
                        swap(du, dv);
                    int dist_cycle = min(du - dv, szCycle[onCycle[U]] - (du - dv));
                    dist = dist - 2 + dist_cycle;
                    cout << dist << '\n';
                }
                else
                {
                    cout << -1 << '\n';
                }
            }
            else
            {
                cout << dist << '\n';
            }
        }
    }
}