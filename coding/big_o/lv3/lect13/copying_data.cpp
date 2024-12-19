#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <class T>
struct LazySegTree
{
    vector<T> seg_tree, lazy;
    int n;

    void init(const vector<T> &a)
    {
        n = (int)a.size();
        seg_tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void down(int id, int l, int r)
    {
        if (l != r)
        {
            lazy[2 * id + 1] = lazy[id];
            lazy[2 * id + 2] = lazy[id];
        }
        seg_tree[id] = lazy[id];
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
            seg_tree[id] = val;
            if (l != r)
            {
                lazy[2 * id + 1] = val;
                lazy[2 * id + 2] = val;
            }
            return;
        }
        int m = (l + r) / 2;
        lazyUpdate(2 * id + 1, l, m, fr, to, val);
        lazyUpdate(2 * id + 2, m + 1, r, fr, to, val);
    }

    T lazyQuery(int id, int l, int r, int pos)
    {
        if (lazy[id] != 0)
            down(id, l, r);
        if (pos > r || pos < l)
            return 0;
        if (pos <= l && r <= pos)
            return seg_tree[id];

        int m = (l + r) / 2;

        return max(
            lazyQuery(2 * id + 1, l, m, pos),
            lazyQuery(2 * id + 2, m + 1, r, pos));
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    LazySegTree<int> lst;
    lst.init(b);

    vector<int> x(m + 1), y(m + 1);

    for (int i = 1; i <= m; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int k;
            cin >> x[i] >> y[i] >> k;
            x[i]--; y[i]--;
            lst.lazyUpdate(0, 0, n - 1, y[i], y[i] + k - 1, i);
        }
        else
        {
            int pos;
            cin >> pos;
            pos--;
            int tmp = lst.lazyQuery(0, 0, n - 1, pos);
            // cout << tmp << ' ';
            if(tmp == 0) cout << b[pos] << '\n';
            else cout << a[pos - y[tmp] + x[tmp]] << '\n';
        }
    }

    return 0;
}
