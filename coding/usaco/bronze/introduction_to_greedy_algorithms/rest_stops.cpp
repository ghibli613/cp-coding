#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int l, n, rf, rb; cin >> l >> n >> rf >> rb;
    vector<pair<ll, ll>> cx(n);
    for(int i = 0; i < n; i++) cin >> cx[i].second >> cx[i].first;
    sort(cx.begin(), cx.end());
    vector<pair<ll, ll>> cx_opt;
    ll pos_min = 0;
    for(int i = n - 1; i > -1; i--)
    {
        if(cx[i].second > pos_min)
        {
            cx_opt.push_back(cx[i]);
            pos_min = cx[i].second;
        }
    }
    pos_min = 0; ll ans = 0;
    for(int i = 0; i < (int)cx_opt.size(); i++)
    {
        ans += (cx_opt[i].second - pos_min) * (rf - rb) * cx_opt[i].first;
        pos_min = cx_opt[i].second;
    }
    cout << ans << '\n';
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

