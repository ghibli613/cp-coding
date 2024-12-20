#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000005

int a[MAXN];

class SegmentTree
{
    struct node
    {
        int ans;
        int o, c;
        node()
        {
            ans = 0;
            o = c = 0;
        }
    } arr[4 * MAXN];

public:
    node up(node L, node R)
    {
        node res;
        int t = min(L.o, R.c);
        res.ans = L.ans + R.ans + t;
        res.o = L.o + R.o - t;
        res.c = L.c + R.c - t;
        return res;
    }
    void build(int id, int l, int r)
    {
        if (l == r)
        {
            arr[id].o = (a[l] == 1);  // open bracket
            arr[id].c = (a[l] == -1); // close bracket
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        arr[id] = up(arr[2 * id], arr[2 * id + 1]);
    }
    node get(int id, int l, int r, int u, int v)
    {
        if (v < l || r < u)
        {
            node empty;
            // empty.c = empty.o = INT_MAX;
            return empty;
        }
        if (u <= l && r <= v)
        {
            return arr[id];
        }
        int mid = (l + r) >> 1;
        node L = get(2 * id, l, mid, u, v);
        node R = get(2 * id + 1, mid + 1, r, u, v);
        return up(L, R);
    }
} IT;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        a[i + 1] = ((s[i] == '(') ? 1 : -1);
    int n = s.size();
    IT.build(1, 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << 2 * IT.get(1, 1, n, l, r).ans << '\n';
    }
}