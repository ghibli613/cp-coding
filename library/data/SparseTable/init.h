template <class T>
struct SparseTable
{
    int MAX_LOG = 20, n; // 2^MAX_LOG >= n
    vector<vector<T>> f;
    vector<T> log_2;

    SparseTable(int n_)
    {
        n = n_;
        f.assign(n, vector<T> (MAX_LOG, 0));
        log_2.assign(MAX_LOG, 0);
    }

    
};
