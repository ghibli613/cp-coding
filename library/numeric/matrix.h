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