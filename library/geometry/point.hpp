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