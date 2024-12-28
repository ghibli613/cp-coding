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
        f.assign(n, vector<T> (level + 1, 0));
        log_2.assign(n_log + 1, 0);
    }


};
