#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll first_one_bit(ll k)
{
    ll res = 0;
    while(k)
    {
        k = k >> 1;
        res++;
    }
    return res;
}

void solve()
{
    ll l, k; cin >> l >> k;
    ll first_bit = first_one_bit(k);
    if(l == k) 
    {
        cout << l << '\n';
        return;
    }

    while(true)
    {
        ll L = l & (1LL << (first_bit - 1));
        ll R = k & (1LL << (first_bit - 1));
        if(L != R) break;
        first_bit--;
    }
    
    ll ans1 = k & ((~0LL) << first_bit);
    if(ans1 + (1LL << first_bit) - 1 <= k) cout << ans1 + (1LL << first_bit) - 1 << '\n';
    else cout << ans1 + (1LL << (first_bit - 1)) - 1 << '\n';
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