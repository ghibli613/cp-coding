#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T>
struct SegTree
{
    vector<T> seg_tree;
    int n;

    void init(int _n)
    {
        n = _n;
        seg_tree.assign(4 * n, 0);
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
        seg_tree[id] = seg_tree[2 * id + 1] & seg_tree[2 * id + 2];
    }

    T query(int id, int l, int r, int fr, int to)
    {
        if (fr <= l && r <= to)
            return seg_tree[id];
        if (fr > r || to < l)
            return INT_MAX;

        int m = (l + r) / 2;

        return
            query(2 * id + 1, l, m, fr, to) &
            query(2 * id + 2, m + 1, r, fr, to);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m), q(m);

    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i] >> q[i];
        l[i]--;
    }

    vector<int> sum(n + 1, 0), a(n);
    for (int bit = 0; bit < 30; bit++)
    {
        for (int i = 0; i < n; i++)
            sum[i] = 0;
        for (int i = 0; i < m; i++)
        {
            if ((q[i] >> bit) & 1)
            {
                sum[l[i]]++;
                sum[r[i]]--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                sum[i] += sum[i - 1];

            if (sum[i] > 0)
            {
                a[i] |= (1 << bit);
            }
        }
    }

    SegTree<int> st;
    st.init(n);
    st.buildTree(a, 0, 0, n - 1);
    // cout << st.query(0, 0, n - 1, 0, 0) << '\n';
    for (int i = 0; i < m; i++)
    {
        if (st.query(0, 0, n - 1, l[i], r[i] - 1) != q[i])
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}