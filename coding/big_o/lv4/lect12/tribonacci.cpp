#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 9;
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

    static Matrix pow(const Matrix& A, ll k)
    {
        if(k == 0) return Identity(A.n);
        if(k == 1) return A;
        Matrix TMP = pow(A, k / 2);
        TMP = TMP * TMP;
        if(k & 1)
            TMP = TMP * A;
        return TMP;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;

    Matrix<mint<MOD>> mat(3, 3), base(3, 1);
    mat.a[0][1] = mat.a[1][2] = mat.a[2][0] = mat.a[2][1] = mat.a[2][2] = 1;
    base.a[0][0] = 0;
    base.a[1][0] = 1;
    base.a[2][0] = 2;

    while(cin >> n, n != 0)
    {
        Matrix<mint<MOD>> temp;
        temp = Matrix<mint<MOD>>::pow(mat, n - 1);
        temp = temp * base;
        cout << temp.a[0][0] << '\n';
    }

    return 0;
}