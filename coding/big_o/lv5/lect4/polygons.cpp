#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

int cmp(double x, double y)
{
    return (x + EPS < y) ? -1 : (x > y + EPS);
}

// 2d point and vector
struct Point
{
    double x, y;

    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    int cmp(const Point &q) const
    {
        int temp = ::cmp(x, q.x);
        if (temp != 0)
        {
            return temp;
        }
        return ::cmp(y, q.y);
    }

#define op(x) \
    bool operator x(const Point &q) const { return cmp(q) x 0; }
    op(>) op(<) op(==) op(>=) op(<=) op(!=)
#undef op
        
    Point operator-(const Point &q) const
    {
        return Point(x - q.x, y - q.y);
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
};

istream &operator>>(istream &is, Point &p)
{
    return is >> p.x >> p.y;
}

ostream &operator<<(ostream &os, Point &p)
{
    return os << "[" << p.x << ',' << p.y << "],";
}

using Polygon = vector<Point>;

int ccw(Point a, Point b, Point c)
{
    return cmp((b - a).cross(c - a), 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Polygon a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int m;
    cin >> m;
    while (m--)
    {
        Point p;
        cin >> p;
        if (ccw(a[0], a[1], p) >= 0)
        {
            cout << "NO";
            return 0;
        }
        
        if (ccw(a[0], a[n - 1], p) <= 0)
        {
            cout << "NO";
            return 0;
        }
        
        int l = 1, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (ccw(a[0], a[mid], p) < 0)
                l = mid + 1;

            else
                r = mid;
            
        }
        if (ccw(a[l - 1], a[l], p) >= 0)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
