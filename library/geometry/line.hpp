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