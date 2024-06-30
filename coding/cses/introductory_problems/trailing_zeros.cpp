#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; cin >> n;
    ll ans = 0;
    while(n / 5)
    {
        ans += n / 5;
        n /= 5;
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