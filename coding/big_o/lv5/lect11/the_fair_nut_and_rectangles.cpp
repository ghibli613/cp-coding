#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

struct Line
{
    ll a, b;

    Line(ll a = 0, ll b = 0) : a(a), b(b) {}

    double intersectX(const Line& l) const
    {
        return 1.0 * (l.b - b) / (a - l.a);
    }

    ll eval(ll x) const
    {
        return a * x + b;
    }
};

struct Rect
{
    ll x, y, a;

    Rect(ll x = 0, ll y = 0, ll a = 0) : x(x), y(y), a(a) {}

    bool operator < (const Rect& r) const
    {
        return x < r.x;
    }
};

int n;
vector<Rect> rects;
deque<Line> cht; // convex hull trict

// add line y = ax + b
void add(ll a, ll b)
{
    Line line(a, b);
    while((int)cht.size() >= 2 && cht[0].intersectX(cht[1]) <= cht[0].intersectX(line))
        cht.pop_front();
    cht.push_front(line);
}

ll query(ll x)
{
    if((int)cht.size() == 0) return 0;

    int l = 0, r = cht.size() - 1;
    ll res = cht[r].eval(x);
    while(l < r)
    {
        int m = (l + r) / 2;
        if(cht[m].intersectX(cht[m + 1]) >= x)
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ll x, y, a;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> a;
        rects.emplace_back(x, y, a);
    }

    sort(rects.begin(), rects.end());
    ll res = 0;
    add(0, 0);

    for(int i = 0; i < n; i++)
    {
        x = rects[i].x; y = rects[i].y; a = rects[i].a;
        ll temp = x * y - a + query(y);
        res = max(res, temp);
        add(-x, temp);
    }
    cout << res;

    return 0;
}