#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    vector<pair<int, int>> b(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
        b[i] = {a[i], i};
    }

    sort(b.begin(), b.end());
    vector<int> val(n + 2);
    int d = 0;
    for(int i = 0; i <= n; i++)
    {
        if (i == 0 || b[i].first != b[i - 1].first) d++;
        val[d] = a[b[i].second]; 
        a[b[i].second] = d;
    }
    vector<int> MIN(d + 2), MAX(d + 2);

    // function<bool(int)> ok = [&](int lim) 
    // {
    //     for(int i = 1; i <= d + 1) MIN[i] = , MAX[i] = -oo;
    //     int f0, f1;
    //     upd(0, a[0], 0); upd(1, a[0], 0);
    //     REP(i, 1, n) {
    //         int tmp = lower_bound(val + 1, val + 1 + d, val[a[i]] - lim) - val;
    //         f0 = get(0, tmp) + 1; f1 = get(1, tmp) + 1;
    //         upd(0, a[i], f0); upd(1, a[i], f1);
    //     }
    //     return f0 <= k && k <= f1;
    //     return true;
    // };

    int l = a[0], r = a[n], ans = 0;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(ok(mid))
        {
            ans = mid; 
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}