const int MAX = 1e5 + 10;

int f1[MAX], f2[MAX];
int n;

void update(int f[], int id, int val)
{
    while(id <= n)
    {
        f[id] += val;
        id += id & -id;
    }
}

int getSum(int f[], int id)
{
    int sum = 0;
    while(id > 0)
    {
        sum += f[id];
        id -= id & -id;
    }
    return sum;
}

void updateRange (int l, int r, int val)
{
    update(f1, l, val);
    update(f1, r + 1, -val);
    update(f2, l, val *(l - 1));
    update(f2, r + 1, -val * r);
}

int prefixSum(int id)
{
    return getSum(f1, id) * id - getSum(f2, id);
}

int sumRange(int l, int r)
{
    return prefixSum(r) - prefixSum(l - 1);
}

int main()
{
    ios::sync_with_stdio(0);

    int q, t, l, r, x;

    cin >> n >> q;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> l >> r >> x;
            updateRange(l, r, x);
        }
        else
        {
            cin >> l >> r;
            cout << sumRange(l, r) << "\n'"
        }
    }
}