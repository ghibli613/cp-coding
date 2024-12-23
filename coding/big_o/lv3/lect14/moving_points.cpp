#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n;

template <class T>
struct FenwickTree
{
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
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<ii> point(n);
    vector<int> speed;
    for (int i = 0; i < n; i++)
    {
        cin >> point[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> point[i].second;
    }
    sort(point.begin(), point.end());

    for (int i = 0; i < n; i++)
        speed.push_back(point[i].second);
    sort(speed.begin(), speed.end());
    speed.resize(unique(speed.begin(), speed.end()) - speed.begin());

    ll res = 0;
    FenwickTree<ll> cnt(speed.size()), f(speed.size());
    for (int i = 0; i < n; i++)
    {
        int pos = lower_bound(speed.begin(), speed.end(), point[i].second) - speed.begin();
        res += cnt.getSum(pos + 1) * 1LL * point[i].first - f.getSum(pos + 1);
        cnt.update(pos + 1, 1);
        f.update(pos + 1, point[i].first);
    }
    cout << res << endl;
}