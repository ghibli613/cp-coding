#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y){}
};

int xCompare(const Point& p1, const Point& p2)
{
    return p1.x < p2.x;
}

int yCompare(const Point& p1, const Point& p2)
{
    return p1.y < p2.y;
}

double dist(Point p1, Point p2)
{
    double dx = 1.0 * (p1.x - p2.x) * (p1.x - p2.x);
    double dy = 1.0 * (p1.y - p2.y) * (p1.y - p2.y);
    return sqrt(dx + dy);
}

tuple<double, pair<Point, Point>> stripClosest(vector<Point> points, int n, tuple<double, pair<Point, Point>> d)
{
    tuple<double, pair<Point, Point>> res = d;
    sort(points.begin(), points.end(), yCompare);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n && points[j].y - points[i].y <= get<0>(res); j++)
        {
            double gasp = dist(points[i], points[j]);
            if(gasp < get<0>(res)) res = {gasp, {points[i], points[j]}};
        }
    
    return res;
}

tuple<double, pair<Point, Point>> closestPair(vector<Point>& points, int left, int right)
{
    if(left >= right) return {INF,{points[left], points[right]}};
    if(right - left == 1) return {dist(points[left], points[right]), {points[left], points[right]}};

    int mid = (left + right) / 2;
    Point pMid = points[mid];
    tuple<double, pair<Point, Point>> minLeft = closestPair(points, left, mid);
    tuple<double, pair<Point, Point>> minRight = closestPair(points, mid + 1, right);

    tuple<double, pair<Point, Point>> res;
    if(get<0>(minLeft) <= get<0>(minRight)) res = minLeft;
    else res = minRight;

    vector<Point> strip;
    for(int i = left; i <= right; i++)
        if(abs(points[i].x - pMid.x) <= get<0>(res))
            strip.push_back(points[i]);

    tuple<double, pair<Point, Point>> minMid = stripClosest(strip, strip.size(), res);
    if(get<0>(minMid) < get<0>(res)) res = minMid;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<Point> points0(n);
    for(int i = 0; i < n; i++) cin >> points0[i].x >> points0[i].y;

    vector<Point> points = points0;
    sort(points.begin(), points.end(), xCompare);
    tuple<double, pair<Point, Point>> res = closestPair(points, 0, n - 1);
    int a = -1, b = -1;
    Point p1 = get<1>(res).first, p2 = get<1>(res).second;
    for(int i = 0; i < n; i++)
    {
        if(p1.x == points0[i].x && p1.y == points0[i].y)
            a = i;
        if(p2.x == points0[i].x && p2.y == points0[i].y)
            b = i;
    }
    if(a > b) cout << b << ' ' << a << ' ' << fixed << setprecision(6) << get<0>(res);
    else cout << a << ' ' << b << ' ' << fixed << setprecision(6) << get<0>(res);

    return 0;
}