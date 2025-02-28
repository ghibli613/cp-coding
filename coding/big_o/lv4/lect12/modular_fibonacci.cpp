#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;
const int N = 1e5 + 7;

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
                {
                    C.a[i][j] += ((this->a[i][k] * B.a[k][j]) % MOD);
                    // C.a[i][j] += MOD;
                    C.a[i][j] %= MOD;
                }
        
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

    int n, m;
    ll mod[20];
    mod[0] = 1;
    for(int i = 1; i < 20; i++) mod[i] = mod[i - 1] * 2;

    Matrix<ll> mat(2, 2), base(2, 1);
    mat.a[0][1] = 0;
    mat.a[0][1] = mat.a[1][0] = mat.a[1][1] = 1;
    base.a[0][0] = 0;
    base.a[1][0] = 1;

    while(cin >> n >> m)
    {
        MOD = mod[m];
        Matrix<ll> temp;
        temp = Matrix<ll>::pow(mat, n);
        temp = temp * base;
        cout << temp.a[0][0] << '\n';
    }

    return 0;
}