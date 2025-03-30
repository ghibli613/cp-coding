#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-12;

int cmp(double x, double y)
{
    return (x < y + EPS) ? -1 : (x > y + EPS);
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

    double dot(const Point &q) const
    {
        return x * q.x + y * q.y;
    }

    double cross(const Point &q) const
    {
        return x * q.y - y * q.x;
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
        return a * A.x + b * A.y + c;
    }
};

bool areParallel(Line l1, Line l2)
{
    return cmp(l1.a * l2.b, l2.a * l1.b) == 0;
}

bool areSame(Line l1, Line l2)
{
    return areParallel(l1, l2) && cmp(l1.c * l2.a, l2.c * l1.a) == 0 && cmp(l1.b * l2.c, l2.b * l1.c) == 0;
}

bool areIntersect(Line l1, Line l2, Point &p)
{
    if (areParallel(l1, l2))
        return false;
    double dx = l1.b * l2.c - l2.b * l1.c;
    double dy = l1.c * l2.a - l2.c * l1.a;
    double d = l1.a * l2.b - l2.a * l1.b;
    p = Point(dx / d, dy / d);
    return true;
}

double Dist(Point &a, Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dist(Point &a, Point &b)
{
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

int main()
{
    double a, b, c, x1, y1, x2, y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;

    Line l(a, b, c);
    Point A(x1, y1), B(x2, y2);

    Point A1(x1, -(a * x1 + c) * 1.0 / b);
    Point B1(x2, -(a * x2 + c) * 1.0 / b);

    Point A2(-(b * y1 + c) * 1.0 / a, y1);
    Point B2(-(b * y2 + c) * 1.0 / a, y2);

    double d, d1, d2, d3, d4;

    d1 = dist(A, A1) + Dist(A1, B1) + dist(B1, B);
    d2 = dist(A, A1) + Dist(A1, B2) + dist(B2, B);
    d3 = dist(A, A2) + Dist(A2, B1) + dist(B1, B);
    d4 = dist(A, A2) + Dist(A2, B2) + dist(B2, B);

    d = dist(A, B);
    d = min(min(min(min(d, d1), d2), d3), d4);

    cout << setprecision(10) << fixed << d << endl;

    return 0;
}