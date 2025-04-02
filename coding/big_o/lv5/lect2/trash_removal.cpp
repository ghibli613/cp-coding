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

struct Line
{
    double a, b, c;
    Point A, B;

    Line(double a, double b, double c) : a(a), b(b), c(c) {}

    Line(Point A, Point B) : A(A), B(B)
    {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -(a * A.x + b * A.y);
    }

    Line(Point P, double k)
    {
        a = -k;
        b = 1;
        c = k * P.x - P.y;
    }

    double f(Point A)
    {
        return a * A.x + b * A.y;
    }
};

bool areParallel(Line l1, Line l2)
{
    return cmp(l1.a * l2.b, l1.b * l2.a) == 0;
}

bool areSame(Line l1, Line l2)
{
    return areParallel(l1, l2) && cmp(l1.c * l2.a, l2.c * l1.a) == 0 && cmp(l1.c * l2.b, l1.b *l2.c) == 0;
}

bool areIntersect(Line l1, Line l2, Point &p)
{
    if(areParallel(l1, l2)) return false;
    double dx = l1.b * l2.c - l2.b * l1.c;
    double dy = l1.c * l2.a - l2.c * l1.a;
    double d = l1.a * l2.b - l2.a * l1.b;
    p = Point(dx / d, dy / d);
    return true;
}

double distToLine(Point p, Point a, Point b, Point &c)
{
    Point ap = p - a, ab = b - a;
    double k = ap.dot(ab) / ab.norm();
    c = a + (ab * k);
    return (p - c).len();
}

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cs = 0;

    while(cin >> n, n != 0)
    {
        Polygon p(n);
        for(int i = 0; i < n; i++)
            cin >> p[i].x >> p[i].y;

        convexHull(p);
        n = p.size();

        double ans = 1e9;
        for(int i = 0; i < n; i++)
        {
            Point H;
            double ah = 0;
            for(int j = 0; j < n ; j++)
            {
                ah = max(distToLine(p[j], p[i], p[(i + 1) % n], H), ah);
            }
            ans = min(ans, ah);
        }
        printf("Case %d: %.2lf\n", ++cs, ceil(ans * 100.0) / 100.0);
    }

    return 0;
}