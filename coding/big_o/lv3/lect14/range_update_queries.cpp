#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T>
struct FenwickTree
{
    int n;
    vector<T> f;

    FenwickTree(int n_)
    {
        n = n_;
        f.assign(n, 0);
        // f1.assign(n, 0);
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
        return getSum(r) - getSum(l - 1);
    }

    void updateRange (int l, int r, int val)
    {
        update(l, val);
        update(r + 1, -val);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];

    FenwickTree<ll> ftr(n + 1);
    for(int i = 1; i <= n; i++)
        ftr.update(i, a[i] - a[i - 1]);

    while(q--)
    {
        int t, l; cin >> t >> l;
        if(t == 1)
        {
            int r, val; cin >> r >> val;
            ftr.updateRange(l, r, val);
        }
        else
        {
            cout << ftr.getSum(l) << '\n';
        }
    }

    return 0;
}