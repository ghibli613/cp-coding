#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

const double EPS = 1e-9;

int cmp(double x, double y)
{
    if (x < y - EPS)
        return -1;
    else if (x > y + EPS)
        return 1;
    else
        return 0;
}

struct Point
{
    double x, y;

    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    int p_compare(const Point &q) const
    {
        if (cmp(x, q.x) != 0)
            return cmp(x, q.x);
        return cmp(y, q.y);
    }

    bool operator>(const Point &q) const { return p_compare(q) > 0; }
    bool operator<(const Point &q) const { return p_compare(q) < 0; }
    bool operator==(const Point &q) const { return p_compare(q) == 0; }
    bool operator>=(const Point &q) const { return p_compare(q) >= 0; }
    bool operator<=(const Point &q) const { return p_compare(q) <= 0; }
    bool operator!=(const Point &q) const { return p_compare(q) != 0; }

    Point operator+(const Point &q) const
    {
        return Point(x + q.x, y + q.y);
    }

    Point operator-(const Point &q) const
    {
        return Point(x - q.x, y - q.y);
    }

    Point operator*(double k) const
    {
        return Point(x * k, y * k);
    }

    Point operator/(double k) const
    {
        return Point(x / k, y / k);
    }

    double dot(const Point &q) const
    {
        return x * q.x + y * q.y;
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

    Point rotate(double alpha)
    {
        double cosa = cos(alpha), sina = sin(alpha);
        return Point(x * cosa - y * sina, x * sina + y * cosa);
    }
};

using Polygon = vector<Point>;

double signedArea(const Polygon &p)
{
    double area = 0;
    for (int j, i = 0; i < (int)p.size(); i++)
    {
        j = (i + 1) % (int)p.size();
        area += p[i].cross(p[j]);
    }
    return area / 2.0;
}

double area(const Polygon &p)
{
    return fabs(signedArea(p));
}

int ccw(Point a, Point b, Point c)
{
    return cmp((b - a).cross(c - a), 0);
}

// note: Assume there are no 3 collinear points
bool isConvex(const Polygon &p)
{
    int sz = p.size();
    if (sz < 3)
        return false;
    int turn = ccw(p[0], p[1], p[2]);
    for (int i = 1; i < sz; i++)
        if (ccw(p[i], p[(i + 1) % sz], p[(i + 2) % sz]) * turn < 0)
            return false;
    return true;
}

Point pivot;

bool compare(const Point &p, const Point &q)
{
    int tmp = ccw(pivot, p, q);
    if (tmp > 0)
        return true;
    return (tmp == 0 && (p - pivot).norm() < (q - pivot).norm());
}

void convexHull(Polygon &pts, Polygon &up, Polygon &down)
{
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    for (int i = 0; i < (int)pts.size(); i++)
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

int maxDist(Point p, Polygon half)
{
    double res = 0;
    res = max(res, (p - half.front()).len());
    res = max(res, (p - half.back()).len());
    int l = 0, r = half.size() - 1;
    while (r - l > 2)
    {
        int x1 = l + (r - l) / 3;
        int x2 = r - (r - l) / 3;
        if ((p - half[x1]).len() > (p - half[x2]).len())
        {
            r = x2;
        }
        else if ((p - half[x1]).len() < (p - half[x2]).len())
        {
            l = x1;
        }
        else
        {
            l = x1;
            r = x2;
        }
    }
    res = max(res, (p - half[l]).len());
    res = max(res, (p - half[(l + r) / 2]).len());
    res = max(res, (p - half[r]).len());
    return floor(res);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        Polygon pts[2], up[2], down[2];
        for (int i = 0; i < n; i++)
        {
            Point p;
            cin >> p.x >> p.y;
            int type;
            cin >> type;
            pts[type].push_back(p);
        }
        convexHull(pts[0], up[0], down[0]);
        convexHull(pts[1], up[1], down[1]);

        int res = 0;
        for (int i = 0; i < (int)pts[0].size(); i++)
        {
            res = max(res, maxDist(pts[0][i], up[1]));
            res = max(res, maxDist(pts[0][i], down[1]));
        }
        cout << res << '\n';
    }

    return 0;
}