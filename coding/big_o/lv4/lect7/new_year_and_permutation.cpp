#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, mod; cin >> n >> mod;

    vector<ll> f(n + 1);
    f[0] = 1;
    for(int i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;

    ll ans = 0;

    for(int len = 1; len <= n; len++)
    {
        ans += (((((1ll * (n - len + 1) * f[len]) % mod) * (n - len + 1)) % mod) * f[n - len]) % mod;
        ans %= mod;
    }

    cout << ans;

    return 0;
}