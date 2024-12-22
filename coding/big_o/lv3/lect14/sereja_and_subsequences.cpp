#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

template<class T>
struct FenwickTree
{
    vector<T> f;
    int n = 1000000;
    // vector<T> f1;

    FenwickTree()
    {
        f.assign(1000000 + 10, 0);
        // f1.assign(n + 1, 0);
    }

    void update(int id, T val)
    {
        while(id <= n)
        {
            f[id] += val;
            id += id & -id;
        }
    }

    T get(int id)
    {
        T sum = 0;
        while(id > 0)
        {
            sum += f[id];
            sum %= MOD;
            id -= id & -id;
        }
        return sum;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    FenwickTree<ll> ftr;

    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        ll q = (ftr.get(x) + 1) * x;
        ftr.update(x, q - ftr.get(x) + ftr.get(x - 1));
    }
    cout << ftr.get(1000000);
}