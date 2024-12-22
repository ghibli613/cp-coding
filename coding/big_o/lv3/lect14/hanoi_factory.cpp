#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<pair<int, int>, int> piii;

template<class T>
struct FenwickTree
{
    int n;
    vector<T> f;

    FenwickTree(int n_)
    {
        n = n_;
        f.assign(n + 1, 0);
    }

    void update(int id, T val)
    {
        while(id <= n)
        {
            f[id] = max(val, f[id]);
            id += id & -id;
        }
    }

    T getMax(int id)
    {
        T maxx = 0;
        while(id > 0)
        {
            maxx = max(maxx, f[id]);
            id -= id & -id;
        }
        return maxx;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<piii> rings;
    set<int> ms;
    map<int, int> mm;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        int a, b, h; cin >> a >> b >> h;
        rings.push_back({{b, a}, h});
        ms.insert(a);
        ms.insert(b);
    }

    for(int i:ms)
    {
        mm[i] = ++count;
    }

    for(int i = 0; i < n; i++)
    {
        rings[i] = {{mm[rings[i].first.first], mm[rings[i].first.second]}, rings[i].second};
    }
    sort(rings.begin(), rings.end(), greater<piii>());

    FenwickTree<ll> ftr(count);

    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ll tmp = ftr.getMax(rings[i].first.first - 1);
        ans = max(ans, tmp + rings[i].second);
        ftr.update(rings[i].first.second, tmp + rings[i].second);
    }
    cout << ans;

    return 0;
}