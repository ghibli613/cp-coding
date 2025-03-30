#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

const double EPS = 1e-9;

int cmp(double x, double y)
{
    return (x < y - EPS) ? -1 : (x > y + EPS);
}

struct Point
{
    double x, y;

    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    int cmp(const Point& q) const
    {
        if(x != q.x) return ::cmp(x, q.x);
        return ::cmp(y, q.y);
    }

    bool operator>(const Point& q) const { return cmp(q) > 0; }
    bool operator<(const Point& q) const { return cmp(q) < 0; }
    bool operator==(const Point& q) const { return cmp(q) == 0; }
    bool operator>=(const Point& q) const { return cmp(q) >= 0; }
    bool operator<=(const Point& q) const { return cmp(q) <= 0; }
    bool operator!=(const Point& q) const { return cmp(q) != 0; }

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

bool isBetween(Point A, Point B, Point C)
{
    return (A - B).len() + (C - B).len() - (C - A).len() < EPS;
}

double distToLine(Point p, Point a, Point b, Point &c)
{
    Point ap = p - a, ab = b - a;
    double k = ap.dot(ab) / ab.norm();
    c = a + (ab * k);
    return (p - c).len();
}

istream& operator>>(istream& is, Point& p)
{
    is >> p.x >> p.y;
    return is;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<Point> v(n);
    Point p;
    cin >> p;

    double r1 = 0.0, r2 = 1e18;

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        r1 = max(r1, (p - v[i]).len());
        r2 = min(r2, (p - v[i]).len());
    }
    v.push_back(v[0]);
    for(int i = 0; i < n; i++)
    {
        Point p_;
        double dist = distToLine(p, v[i], v[i + 1], p_);
        if(isBetween(v[i], p_, v[i + 1]))
        {
            r2 = min(r2, dist);
        }
    }

    cout << fixed << setprecision(7) << 3.14159265358979323846 * (r1 * r1 - r2 * r2) << '\n';

    return 0;
}