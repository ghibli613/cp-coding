#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1000000007;
ll fact[1000000 + 1];

ll fastMult(ll a, ll b)
{
    ll res = 0;
    a %= MOD;
    b %= MOD;
    while(b > 0)
    {
        if(b & 1) res = (res + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return res;
}

ll fastPow(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    while(b > 0)
    {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll b)
{
    ll res = fastPow(b, MOD - 2);
    if((res * b) % MOD == 1) return res;
    return -1;
}

ll combination(ll n, ll k)
{
    return fastMult(fact[n], fastMult(modInverse(fact[k]), modInverse(fact[n - k])));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    for(int i = 1; i <= 1000000; i++)
        fact[i] = fastMult(fact[i - 1], i);

    ll n;
    while(cin >> n)
    {
        ll a, b, d; cin >> a >> b >> d;
        ll nCa = combination(n, a);
        ll bCd = combination(b, d);

        ll ans = fastMult(nCa, fastPow(bCd, a));
        cout << ans << '\n';
    }

    return 0;
}