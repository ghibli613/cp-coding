template <class T>
struct SegTree
{
    vector<T> seg;
    int n;

    void init(const vector<T> &a)
    {
        n = (int)a.size();
        seg.assign(4 * n, 0);

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
        seg[id] = min(seg[2 * id + 1], seg[2 * id + 2]);
    }

    T queryMin(int id, int l, int r, int fr, int to)
    {
        if (fr <= l && r <= to)
            return seg[id];
        if (fr > r || to < l)
            return INT_MAX;

        int m = (l + r) / 2;

        return min(
            queryMin(2 * id + 1, l, m, fr, to),
            queryMin(2 * id + 2, m + 1, r, fr, to));
    }

    void updateMin(int id, int l, int r, int pos, T val)
    {
        if (l == r)
        {
            seg[id] = val;
            return;
        }

        int m = (l + r) / 2;
        if (pos <= m)
            updateMin(2 * id + 1, l, m, pos, val);
        else
            updateMin(2 * id + 2, m + 1, r, pos, val);
        seg[id] = min(seg[2 * id + 1], seg[2 * id + 2]);
    }
};
