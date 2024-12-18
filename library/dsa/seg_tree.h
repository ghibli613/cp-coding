const int MAX = 1e5 + 10;
const int INF = 1e9;

int seg_tree[4 * MAX];
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

int queryMin(int seg_tree[], int id, int l, int r, int fr, int to)
{
    if (fr <= l && r <= to)
        return seg_tree[id];
    if (fr > r || to < l)
        return INF;

    int m = (l + r) / 2;

    return min(
        queryMin(seg_tree, 2 * id + 1, l, m, fr, to),
        queryMin(seg_tree, 2 * id + 2, m + 1, r, fr, to));
}

void updateMin(int seg_tree[], int id, int l, int r, int pos, int val)
{
    if (l == r)
    {
        seg_tree[id] = val;
        return;
    }
    
    int m = (l + r) / 2;
    if(pos <= m)
        updateMin(seg_tree, 2 * id + 1, l, m, pos, val);
    else
        updateMin(seg_tree, 2 * id + 2, m + 1, r, pos, val);
    seg_tree[id] = min(seg_tree[2 * id + 1], seg_tree[2 * id + 2]);
}
