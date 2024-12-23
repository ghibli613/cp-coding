const int MAX = 1e5 + 10;

int f[MAX];
int n;

void update(int id, int val)
{
    while(id <= n)
    {
        f[id] += val;
        id += id & -id;
    }
}

int getSum(int id)
{
    int sum = 0;
    while(id > 0)
    {
        sum += f[id];
        id -= id & -id;
    }
    return sum;
}

int sumRange(int l, int r)
{
    return getSum(r) - getSum(l);
}

void updateRange (int l, int r, int val)
{
    update(l, val);
    update(r + 1, -val);
}
