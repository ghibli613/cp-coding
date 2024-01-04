#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll y, x; cin >> y >> x;
    ll base = max(x, y);
    ll ans = (base - 1) * (base - 1);
    if(base % 2 == 0)
        if(y < x) 
            ans += y;
        else 
            ans += y + base - x;
    else
        if(y < x)
            ans += x + base - y;
        else 
            ans += x;
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