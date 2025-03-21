#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x, y;
} T[400002], ans;

node ADD(node x, node y)
{
    int g = __gcd(x.x, y.x);
    node tmp = (node){g, 0};
    if (g == x.x)
        tmp.y += x.y;
    if (g == y.x)
        tmp.y += y.y;
    return tmp;
}

int n, a[100002];

void build(int p, int l, int r)
{
    if (l == r)
    {
        T[p] = (node){a[l], 1};
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r);
    T[p] = ADD(T[p << 1], T[p << 1 | 1]);
}

void ask(int p, int l, int r, int x, int y)
{
    if (l >= x && r <= y)
    {
        ans = ADD(ans, T[p]);
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        ask(p << 1, l, mid, x, y);
    if (y > mid)
        ask(p << 1 | 1, mid + 1, r, x, y);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build(1, 1, n);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        ans = (node){0, 0};
        ask(1, 1, n, l, r);
        cout << r - l + 1 - ans.y << '\n';
    }
}