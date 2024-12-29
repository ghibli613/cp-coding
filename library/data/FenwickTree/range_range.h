// @brief This Fenwick tree manages from 1 index
template <class T>
struct FenwickTree
{
    int n;
    vector<T> f1, f2;

    FenwickTree(int n_)
    {
        n = n_;
        f1.assign(n + 7, 0);
        f2.assign(n + 7, 0);
    }

    void update(vector<T> &f, int id, int val)
    {
        while (id <= n)
        {
            f[id] += val;
            id += id & -id;
        }
    }

    T getSum(vector<T> &f, int id)
    {
        T sum = 0;
        while (id > 0)
        {
            sum += f[id];
            id -= id & -id;
        }
        return sum;
    }

    void updateRange(int l, int r, T val)
    {
        update(f1, l, val);
        update(f1, r + 1, -val);
        update(f2, l, val * (l - 1));
        update(f2, r + 1, -val * r);
    }

    T prefixSum(int id)
    {
        return getSum(f1, id) * id - getSum(f2, id);
    }

    T sumRange(int l, int r)
    {
        return prefixSum(r) - prefixSum(l - 1);
    }
};