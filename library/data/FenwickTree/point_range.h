int n;
vector<T> f;

FenwickTree(int n_)
{
    n = n_;
    f.assign(n + 7, 0);
}

void update(int id, int val)
{
    while(id <= n)
    {
        f[id] += val;
        id += id & -id;
    }
}

T getSum(int id)
{
    T sum = 0;
    while(id > 0)
    {
        sum += f[id];
        id -= id & -id;
    }
    return sum;
}

T sumRange(int l, int r)
{
    return getSum(r) - getSum(l);
}

void updateRange (int l, int r, T val)
{
    update(l, val);
    update(r + 1, -val);
}
