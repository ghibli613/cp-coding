struct Line
{
    ll a, b;

    Line(ll a = 0, ll b = 0) : a(a), b(b) {}

    double intersectX(const Line &l) const
    {
        return 1.0 * (l.b - b) / (a - l.a);
    }

    ll eval(ll x) const { return a * x + b; }
};

struct ConvexHullTrick
{
    deque<Line> cht;

    void add(ll a, ll b)
    {
        Line line(a, b);
        while (cht.size() >= 2 && cht[0].intersectX(cht[1]) <= cht[0].intersectX(line))
            cht.pop_front();
        cht.push_front(line);
    }

    ll get(ll x)
    {
        if (cht.size() == 0)
            return 0;
        int l = 0, r = cht.size() - 1;
        double res = cht[r].eval(x);
        while (l < r)
        {
            int m = (l + r) / 2;
            if (cht[m].intersectX(cht[m + 1]) >= x)
            {
                res = cht[m].eval(x);
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return res;
    }

    // ll query(ll x)
    // {
    //     int n_cht = cht.size();
    //     while(n_cht > 1 && cht[n_cht - 1].intersectX(cht[n_cht - 2]) >= x)
    //     {
    //         cht.pop_back();
    //         n_cht--;
    //     }
    //     return cht[n_cht - 1].eval(x);
    // }
};