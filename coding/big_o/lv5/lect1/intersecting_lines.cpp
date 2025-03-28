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
        if(::cmp(x, q.x) != 0) return ::cmp(x, q.x);
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

void solve()
{
    Point A1, B1, A2, B2;
    cin >> A1.x >> A1.y >> B1.x >> B1.y >> A2.x >> A2.y >> B2.x >> B2.y;

    Line d1(A1, B1), d2(A2, B2);

    if(areParallel(d1, d2))
    {
        if(areSame(d1, d2)) cout << "LINE\n";
        else cout << "NONE\n";
    }
    else
    {
        Point P;
        areIntersect(d1, d2, P);
        cout << "POINT ";
        cout << fixed << setprecision(2) << P.x << ' ' << P.y <<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    cout << "INTERSECTING LINES OUTPUT\n";

    while(t--)
        solve();

    cout << "END OF OUTPUT";

    return 0;
}