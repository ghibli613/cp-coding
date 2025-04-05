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