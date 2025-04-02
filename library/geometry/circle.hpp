struct Circle : Point
{
    double r;

    Circle(double x = 0, double y = 0, double r = 0) : Point(x, y), r(r) {}

    Circle(Point p, double r) : Point(p), r(r) {}

    bool contains(Point p)
    {
        return (*this - p).len() <= r + EPS;
    }
};

vector<Point> intersection(Line l, Circle cir)
{
    double r = cir.r;
    double a = l.a, b = l.b, c = l.c + l.a * cir.x + l.b * cir.y;
    vector<Point> res;

    double x0 = -a * c / (a * a + b * b);
    double y0 = -b * c / (a * a + b * b);

    if(c * c > r * r * (a * a + b * b) + EPS)
        return res;
    else if(fabs(c * c - r * r (a * a + b * b)) < EPS)
    {
        res.push_back(Point(x0, y0) + Point(cir.x, cir.y));
        return res;
    }

    double d = c * c - r * r (a * a + b * b);
    double mult = sqrt(d / (a * a + b * b));
    double ax, ay, bx, by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;

    res.push_back(Point(ax, ay) + Point(cir.x, cir.y));
    res.push_back(Point(bx, by) + Point(cir.x, cir.y));
    return res;
}