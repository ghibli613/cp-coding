#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

int pre[100010], loc[100010], arr[100010], tree[400007];

struct Query
{
    ll x, y, r, in;
} que[50007];

bool comp(Query a, Query b)
{
    if (a.x < b.x)
        return true;
    else
        return false;
}

bool comp2(Query a, Query b)
{
    if (a.in < b.in)
        return true;
    else
        return false;
}

void create(ll n, ll b, ll e)
{
    if (b == e)
    {
        tree[n] = arr[b];
        return;
    }

    ll l, r, m;
    l = 2 * n;
    r = l + 1;
    m = (b + e) / 2;
    create(l, b, m);
    create(r, m + 1, e);
    tree[n] = tree[l] + tree[r];
}

ll query(ll n, ll b, ll e, ll i, ll j)
{
    if (j < b || e < i)
        return 0;

    if (i <= b && e <= j)
    {
        return tree[n];
    }

    ll l, r, m, ab, cd;
    l = 2 * n;
    r = l + 1;
    m = (b + e) / 2;

    ab = query(l, b, m, i, j);
    cd = query(r, m + 1, e, i, j);

    return (ab + cd);
}

void update(ll n, ll b, ll e, ll i, ll x)
{
    if (i < b || e < i)
        return;

    if (i <= b && e <= i)
    {
        tree[n] = x;
        return;
    }

    ll l, r, m;
    l = 2 * n;
    r = l + 1;
    m = (b + e) / 2;

    update(l, b, m, i, x);
    update(r, m + 1, e, i, x);

    tree[n] = tree[l] + tree[r];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++)
    {
        cout << "Case " << cs << ":\n";
        int n, q;
        cin >> n >> q;

        for (int i = 0; i <= 100005; i++)
        {
            pre[i] = loc[i] = arr[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            int x; cin >> x;
            if (pre[x] == 0)
            {
                pre[x] = i;
                arr[i] = 1;
            }
            else
            {
                loc[pre[x]] = i; // loc is next position
                pre[x] = i;
            }
        }

        create(1, 1, n);

        for (int i = 1; i <= q; i++)
        {
            cin >> que[i].x >> que[i].y;
            que[i].in = i;
        }

        sort(que + 1, que + q + 1, comp);

        int j = 1;

        for (int i = 1; i <= q; i++)
        {
            while (j < que[i].x)
            {
                if (loc[j] != 0)
                {
                    update(1, 1, n, loc[j], 1);
                }
                j++;
            }
            que[i].r = query(1, 1, n, que[i].x, que[i].y);
        }

        sort(que + 1, que + q + 1, comp2);

        for (int i = 1; i <= q; i++)
            cout << que[i].r << '\n';
    }

    return 0;
}