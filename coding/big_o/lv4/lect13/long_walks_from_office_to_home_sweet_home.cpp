#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
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

template<class T>
struct Matrix
{
    vector<vector<T>> a;
    int n, m;

    Matrix(int n = 0, int m = 0) : n(n), m(m)
    {
        a.assign(n, vector<T>(m, 0));
    }

    Matrix operator*(const Matrix& B)
    {
        Matrix C(this->n, B.m);

        for(int i = 0; i < this->n; i++)
            for(int j = 0; j < B.m; j++)
                for(int k = 0; k < this->m; k++)
                    C.a[i][j] += this->a[i][k] * B.a[k][j];

        return C;
    }

    friend ostream &operator<<(ostream& os, const Matrix<T>& mt)
    {
        for(int i = 0; i < mt.n; i++)
        {
            for(int j = 0; j < mt.m; j++)
                os << mt.a[i][j] << " ";
            os << "\n";
        }
        return os;
    }

    static Matrix Identity(int n)
    {
        Matrix I(n, n);
        for(int i = 0; i < n; i++)
            I.a[i][i] = 1;
        return I;
    }

    friend Matrix pow(const Matrix& A, ll k)
    {
        if(k == 0) return Identity(A.n);
        if(k == 1) return A;
        Matrix Exp = pow(A, k / 2);
        Exp = Exp * Exp;
        if(k & 1)
            Exp = Exp * A;
        return Exp;
    }
};

void solve()
{
    int n, u, v;
    ll k;
    cin >> n >> k >> u >> v;
    Matrix<mint<MOD>> A(n, n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A.a[i][j];
    
    A = pow(A, k);
    cout << A.a[u][v] << '\n';
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