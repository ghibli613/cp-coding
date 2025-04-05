#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

const double EPS = 1e-9;

int cmp(double x, double y)
{
    if(x < y - EPS)
        return -1;
    else if(x > y + EPS)
        return 1;
    else return 0;
}

struct Point
{
    double x, y;

    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    int p_compare(const Point& q) const
    {
        if(cmp(x, q.x) != 0) return cmp(x, q.x);
        return cmp(y, q.y);
    }

    bool operator>(const Point& q) const { return p_compare(q) > 0; }
    bool operator<(const Point& q) const { return p_compare(q) < 0; }
    bool operator==(const Point& q) const { return p_compare(q) == 0; }
    bool operator>=(const Point& q) const { return p_compare(q) >= 0; }
    bool operator<=(const Point& q) const { return p_compare(q) <= 0; }
    bool operator!=(const Point& q) const { return p_compare(q) != 0; }

    Point operator+(const Point& q) const
    {
        return Point(x + q.x, y + q.y);
    }

    Point operator-(const Point& q) const
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

    double dot(const Point& q) const
    {
        return x * q.x + y * q.y;
    }

    double cross(const Point& q) const
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

double signedArea(const Polygon& p)
{
    double area = 0;
    for(int j, i = 0; i < (int)p.size(); i++)
    {
        j = (i + 1) % (int)p.size();
        area += p[i].cross(p[j]);
    }
    return area / 2.0;
}

double area(const Polygon& p)
{
    return fabs(signedArea(p));
}

int ccw(Point a, Point b, Point c)
{
    return cmp((b - a).cross(c - a), 0);
}

// note: Assume there are no 3 collinear points
bool isConvex(const Polygon& p)
{
    int sz = p.size();
    if(sz < 3) return false;
    int turn = ccw(p[0], p[1], p[2]);
    for(int i = 1; i < sz; i++)
        if(ccw(p[i], p[(i + 1) % sz], p[(i + 2) % sz]) * turn < 0)
            return false;
    return true;
}

Point pivot;

bool compare(const Point& p, const Point& q)
{
    int tmp = ccw(pivot, p, q);
    if(tmp > 0) return true;
    return (tmp == 0 && (p - pivot).norm() < (q - pivot).norm());
}

void convexHull(Polygon& pts)
{
    pivot = pts[0];
    for(int i = 1; i < (int)pts.size(); i++)
        if(cmp(pivot.y, pts[i].y) > 0 || (cmp(pivot.y, pts[i].y) == 0 && cmp(pivot.x, pts[i].x) > 0))
            pivot = pts[i];

    sort(pts.begin(), pts.end(), compare);
    // remove duplicate points
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    if(pts.size() < 3) return;

    int n = 0;
    for(int i = 0; i < (int)pts.size(); i++)
    {
        while(n > 1 && ccw(pts[n - 2], pts[n - 1], pts[i]) <= 0) n--;
        pts[n++] = pts[i];
    }
    pts.resize(n);
}

bool inTriangle(Point p, Point a, Point b, Point c)
{
    return cmp(area({a, b, c}), area({p, a, b}) + area({p, a, c}) + area({p, b, c})) == 0;
}

bool inPolygon(Point p, Polygon &pts)
{
    if((int)pts.size() < 2) return false;
    if((int)pts.size() == 2)
    {
        return cmp((pts[0] - pts[1]).len(), (pts[0] - p).len() + (pts[1] - p).len()) == 0;
    }
    pivot = pts[0];
    int p1 = lower_bound(pts.begin(), pts.end(), p, compare) - pts.begin();
    if(p1 == (int)pts.size() || p1 == 0) return false;
    return inTriangle(p, pts[0], pts[p1 - 1], pts[p1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    Polygon pts[2], convex[2];
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            Point p;
            cin >> p.x >> p.y;
            pts[i].push_back(p);
        }
        convex[i] = pts[i];
        convexHull(convex[i]);
    }

    vector<int> res(2, 0);
    for(int i = 0; i < 2; i++)
    {
        for(Point p : pts[1 - i])
            if(inPolygon(p, convex[i])) res[i]++;
    }
    cout << res[0] << ' ' << res[1];
    return 0;
}