#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 1e9;

int cmp(double x, double y)
{
    return (x + EPS < y) ? -1 : (x > y + EPS);
}

struct Point
{
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    int cmp(const Point &q) const
    {
        if (x != q.x)
            return ::cmp(x, q.x);
        return ::cmp(y, q.y);
    }
#define op(x) \
    bool operator x(const Point &q) const { return cmp(q) x 0; }
    op(>) op(<) op(==) op(>=) op(<=) op(!=)
#undef op
        Point
        operator-(const Point &q) const
    {
        return Point(x - q.x, y - q.y);
    }
    double cross(const Point &q) const
    {
        return x * q.y - y * q.x;
    }
    double norm()
    {
        return x * x + y * y;
    }
    double len()
    {
        return sqrt(norm());
    }
};

using Polygon = vector<Point>;

double dist(Point a, Point b)
{
    return (a - b).len();
}

double P(Polygon &a)
{
    double ans = 0;
    for (int i = 0; i < a.size(); i++)
        ans += dist(a[i], a[(i + 1) % a.size()]);
    return ans;
}

int ccw(Point a, Point b, Point c)
{
    return cmp((b - a).cross(c - a), 0);
}

void convexHull(Polygon &pts)
{
    // sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    Polygon up, down;
    int n = 0, m = 0;
    for (int i = 0; i < pts.size(); i++)
    {
        while (up.size() > 1 && ccw(up[up.size() - 2], up[up.size() - 1], pts[i]) >= 0)
            up.pop_back();
        up.push_back(pts[i]);
        while (down.size() > 1 && ccw(down[down.size() - 2], down[down.size() - 1], pts[i]) <= 0)
            down.pop_back();
        down.push_back(pts[i]);
    }
    pts = down;
    for (int i = up.size() - 2; i > 0; i--)
        pts.push_back(up[i]);
}

istream &operator>>(istream &is, Point &p)
{
    return is >> p.x >> p.y;
}

ostream &operator<<(ostream &os, Point &p)
{
    return os << p.x << ' ' << p.y;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, tc = 0;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        Polygon pts(n);
        vector<int> v(n), l(n);
        for (int i = 0; i < n; i++)
        {
            cin >> pts[i] >> v[i] >> l[i];
        }
        vector<int> ind(n);
        for (int i = 0; i < n; i++)
        {
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(), [&](int i, int j)
             { return pts[i] < pts[j]; });
        int minValue = INF;
        int minNum = INF, resMask;
        double extraWood = 0;
        for (int mask = 0; mask < 1 << n; mask++)
        {
            Polygon temp;
            int totalValue = 0, totalLeng = 0;
            for (int i = 0; i < n; i++)
            {
                if (mask >> i & 1)
                {
                    totalValue += v[ind[i]];
                    totalLeng += l[ind[i]];
                }
                else
                {
                    temp.push_back(pts[ind[i]]);
                }
            }
            convexHull(temp);
            double extra = totalLeng - P(temp);
            if (extra > EPS)
            {
                if (totalValue < minValue || (totalValue == minValue && n - temp.size() < minNum))
                {
                    minNum = n - temp.size();
                    minValue = totalValue;
                    resMask = mask;
                    extraWood = extra;
                }
            }
        }
        cout << "Forest " << (++tc) << '\n';
        cout << "Cut these trees: ";
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (resMask >> i & 1)
            {
                res.push_back(ind[i] + 1);
            }
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < (int)res.size(); i++)
        {
            cout << res[i] << ' ';
        }
        cout << '\n';
        cout << fixed << setprecision(2) << "Extra wood: " << extraWood << '\n';
        cout << '\n';
    }
    return 0;
}