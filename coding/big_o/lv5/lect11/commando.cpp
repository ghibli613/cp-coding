#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair

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

#define sqr(x) 1LL * (x) * (x)
void run_case()
{
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> x(n);
    for (int &i : x)
    {
        cin >> i;
    }
    ConvexHullTrick cht;
    cht.add(0, 0);
    long long preSum = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += x[i];
        long long f = cht.get(preSum) + a * sqr(preSum) + b * preSum + c;
        if (i == n - 1)
        {
            cout << f << '\n';
            return;
        }
        cht.add(-2 * preSum * a, f + a * sqr(preSum) - b * preSum);
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    
    int num_test;
    cin >> num_test;
    while (num_test--)
    {
        run_case();
    }
    return 0;
}