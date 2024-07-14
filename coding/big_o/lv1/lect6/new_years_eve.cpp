#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k; cin >> n >> k;
    if(k < 2) cout << n;
    else 
    {
        ll d = 0;
        while(n)
        {
            n = n >> 1;
            d++;
        }
        ll ans = ((ll)1 << d) - 1;
        cout << ans;
    }
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