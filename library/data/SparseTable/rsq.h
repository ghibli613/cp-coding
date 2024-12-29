template <class T>
struct SparseTable
{
    int level, n; // 2^MAX_LOG >= n
    vector<vector<T>> f;
    vector<T> log_2;

    SparseTable(int n_)
    {
        n = n_;
        level = ceil(log2(n));
        f.assign(n, vector<T>(level + 1, 0));
        log_2.assign(n_log + 1, 0);
    }

    void compute_spare_table(const vector<T> &a)
    {
        for (int i = 0; i < n; i++)
            f[i][0] = a[i];

        for (int j = 1; (1 << j) <= n; j++)
        {
            int step = 1 << (j - 1);
            for (int i = 0; i + 2 * step <= n; i++)
            {
                f[i][j] = f[i][j - 1] + f[i + step][j - 1];
            }
        }
    }

    T sumQuery(int l, int r)
    {
        int k, total = 0;
        for (int k = n_log; k >= 0; k--)
        {
            if (l + (1 << k) - 1 <= r)
            {
                total += f[l][k];
                l += 1 << k;
            }
        }
        return total;
    }

    void compute_log()
    {
        log_2[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            log_2[i] = log_2[i / 2] + 1;
        }
    }
};