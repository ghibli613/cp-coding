#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int N = 2e5 + 7;

int MOD = 1e9 + 9;
int fact[N], invFact[N];

int binpow(int a, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a % MOD;
    int temp = binpow(a, n / 2);
    temp = (1LL * temp * temp) % MOD;
    if (n % 2)
        return (1LL * temp * a) % MOD;
    return temp;
}

int C(int n, int k)
{
    if (n < k || n < 0 || k < 0)
        return 0;
    int Ckn = fact[n];
    int div = 1LL * invFact[n - k] * invFact[k] % MOD;
    Ckn = (1LL * Ckn * div) % MOD;
    return Ckn;
}

int calc(ii x, ii y)
{
    int X = y.first - x.first + 1;
    int Y = y.second - x.second + 1;
    if (X <= 0 || Y <= 0)
        return 0;
    return C(X + Y - 2, X - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
        invFact[i] = binpow(fact[i], MOD - 2);
    }
    int T;
    cin >> T;
    assert(1 <= T && T <= 100);
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<ii> a(k + 1);
        vector<int> f(k + 1, 0);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        a[k] = ii(n, m);
        sort(a.begin(), a.end());
        for (int i = 0; i <= k; i++)
        {
            f[i] = calc(ii(1, 1), a[i]);
            for (int j = 0; j < i; j++)
            {
                f[i] = (f[i] - (1LL * f[j] * calc(a[j], a[i]) % MOD) + MOD) % MOD;
            }
        }
        cout << f[k] << endl;
    }

    return 0;
}