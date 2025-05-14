struct Line
{
    double a, b;

    Line(double a = 0, double b = 0) : a(a), b(b) {}

    bool operator < (const Line& l) const
    {
        if(a != l.a) return a < l.a
        return b > l.b;
    }

    double intersectX(const Line& l) const
    {
        return (l.b - b) / (a - l.a);
    }

    double eval(double x) const
    {
        return a * x + b;
    }
};

vector<Line> buildConvex(const vector<Line>& lines)
{
    vector<Line> res;
    int n = 0;
    for(int i = 0; i < (int)lines.size(); i++)
    {
        while(res.size() >= 2 && res[n - 2].intersectX(res[n - 1]) >= res[n - 1].intersectX(lines[i]))
        {
            res.pop_back();
            n--;
        }
        res.push_back(lines[i]);
        n++;
    }
    return res;
}

double query(const vector<Line>& lines, double x)
{
    int l = 0, r = lines.size() - 1;
    double res = lines[r].eval(x);
    while(l < r)
    {
        int m = (l + r) / 2;
        if(lines[m].intersectX(lines[m + 1]) >= x)
        {
            res = lines[m].eval(x);
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return res;
}

void test()
{
    int n, q;
    cin >> n >> q;

    vector<Line> lines(n);
    for(int i = 0; i < n; i++)
        cin >> lines[i].a >> lines[i].b;

    sort(lines.begin(), lines.end());
    lines = buildConvex(lines);

    while(q--)
    {
        double x;
        cin >> x;
        cout << query(lines, x) << "\n";
    }
}