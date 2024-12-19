template<class T>
struct LazySegTree
{
    vector<T> seg_tree, lazy;
    int n;

    void init(int _n)
    {
        n = _n;
        seg_tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void buildTree(const vector<T>& a, int id, int l, int r)
    {
        if (l == r)
        {
            seg_tree[id] = a[l];
            return;
        }
        int m = (l + r) / 2;
        buildTree(a, 2 * id + 1, l, m);
        buildTree(a, 2 * id + 2, m + 1, r);
        seg_tree[id] = min(seg_tree[2 * id + 1], seg_tree[2 * id + 2]);
    }

    void down(int id, int l, int r)
    {
        if (l != r)
        {
            lazy[2 * id + 1] += lazy[id];
            lazy[2 * id + 2] += lazy[id];
        }
        seg_tree[id] += lazy[id];
        lazy[id] = 0;
    }

    void lazyUpdate(int id, int l, int r,
                    int fr, int to, T val)
    {
        if (lazy[id] != 0)
            down(id, l, r);
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
        lazyUpdate(2 * id + 1, l, m, fr, to, val);
        lazyUpdate(2 * id + 2, m + 1, r, fr, to, val);
        seg_tree[id] = min(seg_tree[2 * id + 1], seg_tree[2 * id + 2]);
    }

    T lazyMinQuery(int id, int l, int r,
                     int fr, int to)
    {
        if (lazy[id] != 0)
            down(id, l, r);
        if (fr > r || to < l)
            return INF;
        if (fr <= l && r <= to)
            return seg_tree[id];

        int m = (l + r) / 2;

        return min(
            lazyMinQuery(2 * id + 1, l, m, fr, to),
            lazyMinQuery(2 * id + 2, m + 1, r, fr, to));
    }
};