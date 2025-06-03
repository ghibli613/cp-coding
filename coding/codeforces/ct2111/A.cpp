#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

void solve()
{
    ll x; cin >> x;
    ll tmp = 1;
    int ans = 2;
    while(tmp < x)
    {
        tmp = tmp * 2 + 1;
        ans += 2;
    }
    ans += 1;
    cout << ans << '\n';
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