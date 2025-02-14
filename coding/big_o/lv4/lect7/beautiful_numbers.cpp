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

vector<mint<MOD>> factor, invert;

int a, b, n;

void precompute()
{
    factor.assign(n + 1, 0);
    invert.assign(n + 1, n);
    factor[0] = 1;
    invert[0] = inv(factor[0]);
    for(int i = 1; i <= n; i++)
    {
        factor[i] = factor[i - 1] * i;
        invert[i] = inv(factor[i]);
    }
}

bool is_good(int x)
{
    while(x)
    {
        int digit = x % 10;
        if(digit != a && digit != b) return false;
        x /= 10;
    }
    return true;
}

mint<MOD> nCk(int n, int k)
{
    return factor[n] * invert[k] * invert[n - k];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> n;
    precompute();

    mint<MOD> ans = 0;
    if(a == b && is_good(a * n))
    {
        cout << 1 << '\n';
        return 0;
    }

    for(int i = 0; i <= n; i++)
    {
        int tmp = a * i + b * (n - i);
        if(is_good(tmp))
        {
            ans += nCk(n, i);
        }
    }
    cout << ans << '\n';

    return 0;
}