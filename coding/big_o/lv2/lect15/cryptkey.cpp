#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

ll gcd(ll a, ll b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

ll power(ll x, int n)
{
    return (n == 0) ? 1 : (x * power(x, n - 1));
}

vector<pli> factorize(ll n)
{
    vector<pli> res;
    for (long long i = 2; i * i <= n; ++i)
    {
        int cnt = 0;
        while (n % i == 0)
        {
            n /= i;
            ++cnt;
        }
        if (cnt > 0)
            res.push_back({i, cnt});
    }
    if (n > 1)
        res.push_back({n, 1});

    return res;
}

bool solve(vector<ll> &a, ll k)
{
    int n = a.size();

    vector<pli> factors = factorize(k);
    if (k == 1)
        factors.push_back({1, 0});

    ll t = 1;

    for (pli e : factors)
    {
        ll x = power(e.first, e.second);

        ll y = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] % x == 0)
                y = gcd(y, a[i]);

        if (y == 0)
            return false;

        t *= y / gcd(t, y);
    }

    return (t == k);
}

int main()
{
    int nTest;
    cin >> nTest;

    while (nTest--)
    {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        ll k;
        cin >> k;

        if (solve(a, k))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}