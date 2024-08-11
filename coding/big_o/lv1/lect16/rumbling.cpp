#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll x, ll s)
{
    ll tmp = x; ll sumd = 0;
    while(tmp)
    {
        sumd += tmp % 10;
        tmp /= 10;
    }
    if(x - s >= sumd) return 1;
    else return 0;
}

void solve()
{
    ll l, r, s; cin >> l >> r >> s;
    ll R = r;
    while(l <= r)
    {
        ll mid = (r - l) / 2 + l;
        if(check(mid, s))
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << R - r << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}