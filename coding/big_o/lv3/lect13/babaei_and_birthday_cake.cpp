#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const double PI = 3.1415926535897932384626433;

const int MAX = 1e5 + 10;

ll seg_tree[3 * MAX]{LONG_LONG_MIN};
ll a[MAX];
int n;

ll queryMax(int id, int l, int r, int fr, int to)
{
    if (fr <= l && r <= to)
        return seg_tree[id];
    if (fr > r || to < l)
        return LONG_LONG_MIN;

    int m = (l + r) / 2;

    return max(
        queryMax(2 * id + 1, l, m, fr, to),
        queryMax(2 * id + 2, m + 1, r, fr, to));
}

void updateMax(int id, int l, int r, int pos, ll val)
{
    if (l == r)
    {
        seg_tree[id] = val;
        return;
    }
    
    int m = (l + r) / 2;
    if(pos <= m)
        updateMax(2 * id + 1, l, m, pos, val);
    else
        updateMax(2 * id + 2, m + 1, r, pos, val);
    seg_tree[id] = max(seg_tree[2 * id + 1], seg_tree[2 * id + 2]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll r, h;
    vector<pair<ll, ll>> vec;
    for (int i = 1; i <= n; i++)
    {
        cin >> r >> h;
        a[i] = r * r * h;
    }
    for (int i = 1; i <= n; i++)
        vec.push_back({a[i], -i});
    sort(vec.begin(), vec.end());

    updateMax(0, 0, n, 0, 0);
    for (auto p : vec)
    {
        ll id = -p.second;
        ll v = queryMax(0, 0, n, 0, id - 1);
        updateMax(0, 0, n, id, v + p.first);
    }
    double ans = (double)queryMax(0, 0, n, 0, n) * PI;
    cout << fixed << setprecision(9) << ans;
    return 0;
}