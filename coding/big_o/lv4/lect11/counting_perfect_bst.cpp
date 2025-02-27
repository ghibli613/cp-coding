#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e8 + 7;
const int N = 1e5 + 7;

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

vector<ll> values;
vector<mint<MOD>> cat;

void build()
{
    for(ll i = 2; i <= 100000; i++)
        for(ll j = i * i; j <= 10000000000; j *= i)
            values.push_back(j);
    
    sort(values.begin(), values.end());
    values.resize(unique(values.begin(), values.end()) - values.begin());

    cat.assign(values.size() + 1, 0);
    cat[0] = 1;
    for(int i = 0; i < (int)cat.size() - 1; i++)
        cat[i + 1] = cat[i] * (4 * i + 2) / (i + 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    build();
    int t = 1;
    cin >> t;

    for(int test = 1; test <= t; test++)
    {
        cout << "Case " << test << ": ";
        ll a, b; cin >> a >> b;
        int cnt = upper_bound(values.begin(), values.end(), b) - lower_bound(values.begin(), values.end(), a);
        if(cnt == 0) 
            cout << 0 << '\n';
        else
            cout << cat[cnt] << '\n';
    }
    return 0;
}