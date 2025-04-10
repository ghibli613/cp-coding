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

struct Circle
{
    Point I;
    double r;

    Circle(double x = 0, double y = 0, double r = 0) : I(x, y), r(r) {}

    Circle(Point p, double r) : I(p), r(r) {}

    int contains(Point p)
    {
        return cmp((this->I - p).len(), r);
    }
};

void solve()
{
    double x, y, r;
    cin >> x >> y >> r;
    Circle C(x, y, r);
    cin >> x >> y;
    Point P(x, y);
    if(C.contains(P) == 0)
        cout << "OnCircle\n";
    else if(C.contains(P) > 0)
        cout << "Outside\n";
    else cout << "Inside\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 1; tc <= t; tc++)
    {
        cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
}