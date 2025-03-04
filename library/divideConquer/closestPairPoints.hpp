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

double stripClosest(vector<Point> points, int n, double d)
{
    double res = d;
    sort(points.begin(), points.end(), yCompare);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n && points[j].y - points[i].y <= res; j++)
        {
            res = min(res, dist(points[i], points[j]));
        }
    return res;
}

double closestPair(vector<Point>& points, int left, int right)
{
    if(left >= right) return INF;
    if(right - left == 1) return dist(points[left], points[right]);

    int mid = (left + right) / 2;
    Point pMid = points[mid];
    double minLeft = closestPair(points, left, mid);
    double minRight = closestPair(points, mid + 1, right);
    double res = min(minLeft, minRight);

    vector<Point> strip;
    for(int i = left; i <= right; i++)
        if(abs(points[i].x - pMid.x) <= res)
            strip.push_back(points[i]);

    res = min(res, stripClosest(strip, strip.size(), res));
    return res;
}

void test()
{
    int n; cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;

    sort(points.begin(), points.end(), xCompare);
    double res = closestPair(points, 0, n - 1);
    cout << res << "\n";

    return 0;
}