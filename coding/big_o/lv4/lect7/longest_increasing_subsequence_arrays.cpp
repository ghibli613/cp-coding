#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

template <int MOD>
struct mint
{
    int v;
    explicit operator int() const { return v; } // explicit -> don't silently convert to int
    mint() : v(0) {}
    mint(ll _v)
    {
        v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0)
            v += MOD;
    }
    friend bool operator==(const mint &a, const mint &b)
    {
        return a.v == b.v;
    }
    friend bool operator!=(const mint &a, const mint &b)
    {
        return !(a == b);
    }
    friend bool operator<(const mint &a, const mint &b)
    {
        return a.v < b.v;
    }

    mint &operator+=(const mint &o)
    {
        if ((v += o.v) >= MOD)
            v -= MOD;
        return *this;
    }
    mint &operator-=(const mint &o)
    {
        if ((v -= o.v) < 0)
            v += MOD;
        return *this;
    }
    mint &operator*=(const mint &o)
    {
        v = int((ll)v * o.v % MOD);
        return *this;
    }
    mint &operator/=(const mint &o) { return (*this) *= inv(o); }
    friend mint pow(mint a, ll p)
    {
        mint ans = 1;
        assert(p >= 0);
        for (; p; p /= 2, a *= a)
            if (p & 1)
                ans *= a;
        return ans;
    }
    friend mint inv(const mint &a)
    {
        assert(a.v != 0);
        return pow(a, MOD - 2);
    }

    mint operator-() const { return mint(-v); }
    mint &operator++() { return *this += 1; }
    mint &operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint &b) { return a += b; }
    friend mint operator-(mint a, const mint &b) { return a -= b; }
    friend mint operator*(mint a, const mint &b) { return a *= b; }
    friend mint operator/(mint a, const mint &b) { return a /= b; }
    friend ostream &operator<<(ostream &os, const mint &m)
    {
        return os << m.v;
    }
    friend istream &operator>>(istream &is, mint &m)
    {
        ll x;
        is >> x;
        m.v = x;
        return is;
    }
};

vector<mint<MOD>> f;
vector<mint<MOD>> inver;

void computeFactorials(int n)
{
    f.assign(n + 1, 0);
    inver.assign(n + 1, 0);
    f[0] = 1;
    inver[0] = inv(f[0]);
    for(int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * i;
        inver[i] = inv(f[i]);
    }
}

mint<MOD> nCkInverseModulo(int n, ll k)
{
    return f[n] * inver[k] * inver[n - k];
}

void solve()
{
    int m, n; cin >> m >> n;
    if(n == 1) 
    {
        cout << 1 << '\n';
        return;
    }
    mint<MOD> ans = 0;
    mint<MOD> pow1 = 1;
    mint<MOD> pow2 = pow((mint<MOD>)n - 1, m - n);
    mint<MOD> inv_n_1 = inv(mint<MOD>(n - 1));
    for(int i = 0; i <= m - n; i++)
    {
        ans += nCkInverseModulo(m - i - 1, n - 1) * pow1 * pow2;
        pow1 *= n;
        pow2 *= inv_n_1;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    computeFactorials(5 * 1e5);
    while(t--)
        solve();

    return 0;
}