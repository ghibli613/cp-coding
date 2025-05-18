#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

struct Line
{
    ll a, b;

    Line(ll a = 0, ll b = 0) : a(a), b(b) {}

    double intersectX(const Line &l) const
    {
        return 1.0 * (l.b - b) / (a - l.a);
    }

    ll eval(ll x) const { return a * x + b; }
};

struct ConvexHullTrick
{
    deque<Line> cht;

    void add(ll a, ll b)
    {
        Line line(a, b);
        while (cht.size() >= 2 && cht[(int)cht.size() - 1].intersectX(cht[(int)cht.size() - 2]) >= cht[(int)cht.size() - 1].intersectX(line))
            cht.pop_back();
        cht.push_back(line);
    }

    ll get(ll x)
    {
        if (cht.size() == 0)
            return 0;
        int l = 0, r = cht.size() - 1;
        ll res = cht[r].eval(x);
        while (l < r)
        {
            int m = (l + r) / 2;
            if (cht[m].intersectX(cht[m + 1]) >= x)
            {
                res = cht[m].eval(x);
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return res;
    }

    ll query(ll x)
    {
        while((int)cht.size() > 1 && cht[0].intersectX(cht[1]) <= x)
        {
            cht.pop_front();
        }
        return cht[0].eval(x);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll c;
    cin >> n >> c;

    ConvexHullTrick cht;
    ll res = 0;
    for(int i = 1; i <= n; i++)
    {
        ll x; cin >> x;
        cht.add(-2 * x, x * x + res);
        res = cht.query(x) + c + x * x;
    }

    cout << res << '\n';

    return 0;
}