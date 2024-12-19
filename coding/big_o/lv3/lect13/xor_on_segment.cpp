#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <class T>
struct LazySegTree
{
    vector<T> seg_tree, lazy;
    int n;

    void init(int bit, const vector<T> &a)
    {
        n = (int)a.size();
        seg_tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        buildTree(bit, a, 0, 0, n - 1);
    }

    void buildTree(int bit, const vector<T> &a, int id, int l, int r)
    {
        if (l == r)
        {
            seg_tree[id] = (a[l] >> bit) & 1;
            return;
        }
        int m = (l + r) / 2;
        buildTree(bit, a, 2 * id + 1, l, m);
        buildTree(bit, a, 2 * id + 2, m + 1, r);
        seg_tree[id] = seg_tree[2 * id + 1] + seg_tree[2 * id + 2];
    }

    void down(int id, int l, int r)
    {
        if (l != r)
        {
            lazy[2 * id + 1] ^= lazy[id];
            lazy[2 * id + 2] ^= lazy[id];
        }
        seg_tree[id] = (r - l + 1) - seg_tree[id];
        lazy[id] = 0;
    }

    void lazyUpdate(int id, int l, int r, int fr, int to)
    {
        if (lazy[id] != 0)
            down(id, l, r);
        if (fr > r || to < l)
            return;
        if (fr <= l && r <= to)
        {
            seg_tree[id] = (r - l + 1) - seg_tree[id];
            if (l != r)
            {
                lazy[2 * id + 1] ^= 1;
                lazy[2 * id + 2] ^= 1;
            }
            return;
        }
        int m = (l + r) / 2;
        lazyUpdate(2 * id + 1, l, m, fr, to);
        lazyUpdate(2 * id + 2, m + 1, r, fr, to);
        seg_tree[id] = seg_tree[2 * id + 1] + seg_tree[2 * id + 2];
    }

    T lazyQuery(int id, int l, int r, int fr, int to)
    {
        if (lazy[id] != 0)
            down(id, l, r);
        if (fr > r || to < l)
            return 0;
        if (fr <= l && r <= to)
            return seg_tree[id];

        int m = (l + r) / 2;

        return lazyQuery(2 * id + 1, l, m, fr, to) + lazyQuery(2 * id + 2, m + 1, r, fr, to);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<LazySegTree<int>> st(20);

    for (int i = 0; i < 20; i++)
        st[i].init(i, a);
    int m;
    cin >> m;
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            ll answer = 0;
            for (int bit = 0; bit < 20; bit++)
            {
                answer += 1LL * st[bit].lazyQuery(0, 0, n - 1, l - 1, r - 1) * (1 << bit);
            }
            cout << answer << endl;
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            for (int bit = 0; bit < 20; bit++)
            {
                if ((x >> bit) & 1)
                {
                    st[bit].lazyUpdate(0, 0, n - 1, l - 1, r - 1);
                }
            }
        }
    }
    return 0;
}