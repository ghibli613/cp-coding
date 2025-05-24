#include <bits/stdc++.h>
using namespace std;

#define N 111111
#define LN 23

int v[N], pa[N][LN], RM[N], depth[N], maxi = 0;
vector<int> adj[N];
map<int, int> M;

struct node
{
    int count;
    node *left, *right;
    node(int count, node *left, node *right) : count(count), left(left), right(right) {}
    node *insert(int l, int r, int w);
};

node *null = new node(0, NULL, NULL);
node *node::insert(int l, int r, int w)
{
    if (l <= w && w < r)
    {
        if (l + 1 == r)
            return new node(this->count + 1, null, null);
        int m = (l + r) >> 1;
        return new node(this->count + 1, this->left->insert(l, m, w), this->right->insert(m, r, w));
    }
    return this;
}

node *root[N];
void dfs(int cur, int prev)
{
    pa[cur][0] = prev;
    depth[cur] = (prev == -1 ? 0 : depth[prev] + 1);
    root[cur] = (prev == -1 ? null : root[prev])->insert(0, maxi, M[v[cur]]);
    for (int i = 0; i < adj[cur].size(); i++)
        if (adj[cur][i] != prev)
            dfs(adj[cur][i], cur);
}

int LCA(int u, int v)
{
    if (depth[u] < depth[v])
        return LCA(v, u);
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LN; i++)
        if ((diff >> i) & 1)
            u = pa[u][i];
    if (u != v)
    {
        for (int i = LN - 1; i >= 0; i--)
            if (pa[u][i] != pa[v][i])
            {
                u = pa[u][i];
                v = pa[v][i];
            }
        u = pa[u][0];
    }
    return u;
}

int getKth(node *a, node *b, node *c, node *d, int l, int r, int k)
{
    if (l + 1 == r)
        return l;
    int count = a->left->count + b->left->count - c->left->count - d->left->count;
    int m = (l + r) >> 1;
    if (count >= k)
        return getKth(a->left, b->left, c->left, d->left, l, m, k);
    return getKth(a->right, b->right, c->right, d->right, m, r, k - count);
}

int getfreq(node *a, node *b, node *c, node *d, int l, int r, int k)
{
    if (l <= k && k < r)
    {
        if (l + 1 == r)
            return a->count + b->count - c->count - d->count;
        int m = (l + r) >> 1;
        return getfreq(a->left, b->left, c->left, d->left, l, m, k) + getfreq(a->right, b->right, c->right, d->right, m, r, k);
    }
    return 0;
}

void get(int u, int v)
{
    int i, j, l, d, num, mi, freq;
    l = LCA(u - 1, v - 1);
    d = depth[u - 1] + depth[v - 1] - 2 * depth[l] + 1;
    mi = d / 2 + 1;
    num = getKth(root[u - 1], root[v - 1], root[l], (pa[l][0] == -1 ? null : root[pa[l][0]]), 0, maxi, mi);
    freq = getfreq(root[u - 1], root[v - 1], root[l], (pa[l][0] == -1 ? null : root[pa[l][0]]), 0, maxi, num);
    (freq >= mi) ? printf("D %d\n", RM[num]) : printf("S\n");
}

int main()
{
    int i, j, n, m, a, b;
    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        M[v[i]];
    }

    maxi = 0;
    for (auto it : M)
    {
        M[it.first] = maxi;
        RM[maxi] = it.first;
        maxi++;
    }

    for (i = 0; i < n - 1; i++)
    {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(pa, -1, sizeof pa);
    null->left = null->right = null;

    dfs(0, -1);
    for (i = 0; i < LN - 1; i++)
        for (j = 0; j < n; j++)
            if (pa[j][i] != -1)
                pa[j][i + 1] = pa[pa[j][i]][i];

    while (m--)
    {
        scanf("%d %d", &a, &b);
        get(a, b);
    }
    return 0;
}