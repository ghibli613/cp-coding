template <class T>
struct SparseTable
{
    int n_log, n; // 2^MAX_LOG >= n
    vector<vector<T>> f;
    vector<T> log_2;

    SparseTable(int n_)
    {
        n = n_;
        n_log = ceil(log2(n));
        f.assign(n, vector<T> (n_log + 1, 0));
        log_2.assign(n_log + 1, 0);
    }


};
