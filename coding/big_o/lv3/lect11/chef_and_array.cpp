#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;
const int LOG_MAX = 20;
const int INF = 1e9;

int a[MAX];
int f[MAX][LOG_MAX];
int log_2[MAX];
int n, q;

void compute_spare_table()
{
    for(int i = 0; i < n; i++)
        f[i][0] = a[i];

    for(int j = 1; (1 << j) <= n; j++)
    {
        int step = 1 << (j - 1);
        for(int i = 0; i + 2 * step <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + step][j - 1]);
    }
}

int minQuery(int l, int r)
{
    int k = log_2[r - l + 1];
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

void compute_log()
{
    log_2[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        log_2[i] = log_2[i / 2] + 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    compute_spare_table();
    compute_log();

    int l, r;
    cin >> q >> l >> r;

    ll ans = 0;
    for(int i = 0; i < q; i++)
    {
        ans += minQuery(min(l, r), max(l, r));
        // cout << l << ' ' << r << ' ' << minQuery(min(l, r), max(l, r)) << '\n';
        l = (l + 7) % (n - 1);
        r = (r + 11) % n;
        // cout << ans << '\n';
    }
    cout << ans;

    return 0;
}