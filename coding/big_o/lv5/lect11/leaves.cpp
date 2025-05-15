#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Rect = pair<int, int>;

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
        while (cht.size() >= 2 && cht[0].intersectX(cht[1]) >= cht[0].intersectX(line))
            cht.pop_front();
        cht.push_front(line);
    }
    ll get(ll x)
    {
        if (cht.size() == 0)
            return 0;
        int l = 0, r = cht.size() - 1;
        double res = cht[r].eval(x);
        while (l < r)
        {
            int m = (l + r) / 2;
            if (cht[m].intersectX(cht[m + 1]) <= x)
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
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<long long> t(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t[i] = t[i - 1] + a[i];
        s[i] = s[i - 1] + i * a[i];
    }
    long long res = 0;
    vector<ConvexHullTrick> CHT(k + 1);
    CHT[0].add(-1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= 1; j--)
        {
            long long f = CHT[j - 1].get(t[i]) + s[i];
            if (i != n)
                CHT[j].add(-(i + 1), f - s[i] + t[i] * (i + 1));
            if (i == n && j == k)
                res = f;
        }
    }
    cout << res << endl;
    return 0;
}