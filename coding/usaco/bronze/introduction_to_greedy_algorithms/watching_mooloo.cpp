#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; cin >> n >> k;
    vector<ll> d(n);
    for(int i = 0; i < n; i++) cin >> d[i];

    ll ans = k + 1;

    for(int i = 1; i < n; i++)
    {
        if(k + 1 < d[i] - d[i-1]) ans += k + 1;
        else ans += d[i] - d[i - 1];
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