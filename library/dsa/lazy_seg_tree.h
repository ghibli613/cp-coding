const int MAX = 1e5 + 10;
const int INF = 1e9;

int seg_tree[4 * MAX];
int lazy[4 * MAX];
int a[MAX];
int n, q;

void buildTree(int a[], int seg_tree[], int id, int l, int r)
{
    if (l == r)
    {
        seg_tree[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    buildTree(a, seg_tree, 2 * id + 1, l, m);
    buildTree(a, seg_tree, 2 * id + 2, m + 1, r);
    seg_tree[id] = min(seg_tree[2 * id + 1], seg_tree[2 * id + 2]);
}

void down(int seg_tree[], int lazy[], int id, int l, int r)
{
    if (l != r)
    {
        lazy[2 * id + 1] += lazy[id];
        lazy[2 * id + 2] += lazy[id];
    }
    seg_tree[id] += lazy[id];
    lazy[id] = 0;
}

void lazyUpdate(int seg_tree[], int lazy[],
                int id, int l, int r,
                int fr, int to, int val)
{
    if (lazy[id] != 0)
        down(seg_tree, lazy, id, l, r);
    if (fr > r || to < l)
        return;
    if (fr <= l && r <= to)
    {
        seg_tree[id] += val;
        if (l != r)
        {
            lazy[2 * id + 1] += val;
            lazy[2 * id + 2] += val;
        }
        return;
    }
    int m = (l + r) / 2;
    lazyUpdate(seg_tree, lazy, 2 * id + 1, l, m, fr, to, val);
    lazyUpdate(seg_tree, lazy, 2 * id + 2, m + 1, r, fr, to, val);
    seg_tree[id] = min(seg_tree[2 * id + 1], seg_tree[2 * id + 2]);
}

int lazyMinQuery(int seg_tree[], int lazy[],
                 int id, int l, int r,
                 int fr, int to)
{
    if (lazy[id] != 0)
        down(seg_tree, lazy, id, l, r);
    if (fr > r || to < l)
        return INF;
    if (fr <= l && r <= to)
        return seg_tree[id];

    int m = (l + r) / 2;

    return min(
        lazyMinQuery(seg_tree, lazy, 2 * id + 1, l, m, fr, to),
        lazyMinQuery(seg_tree, lazy, 2 * id + 2, m + 1, r, fr, to));
}