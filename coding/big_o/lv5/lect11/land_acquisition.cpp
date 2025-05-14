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
    ll w, l;

    Rect(ll w = 0, ll l = 0) : w(w), l(l) {}

    bool operator < (const Rect& r) const
    {
        if(l == r.l) return w < r.w;
        else return l < r.l;
    }
};

int n;
vector<Rect> rects;
deque<Line> cht; // convex hull trict

// add line y = ax + b
void add(ll a, ll b)
{
    Line line(a, b);
    while((int)cht.size() >= 2 && cht[n - 1].intersectX(cht[n - 2]) >= cht[n - 1].intersectX(line))
        cht.pop_back();
    cht.push_back(line);
}

ll query(ll x)
{
    int n = cht.size();
    while(n > 1 && cht[0].intersectX(cht[1]) <= x)
    {
        cht.pop_front();
        n--;
    }
    return cht[0].eval(x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ll w, l;
    for(int i = 0; i < n; i++)
    {
        cin >> w >> l;
        rects.emplace_back(w, l);
    }

    sort(rects.begin(), rects.end());
    vector<Rect> tmp;
    for(int i = 0; i < n; i++)
    {
        while((int)tmp.size() != 0 && tmp[(int)tmp.size() - 1].w <= rects[i].w)
        {
            tmp.pop_back();
        }
        tmp.push_back(rects[i]);
    }
    rects = tmp;
    n = rects.size();

    ll res = 0;
    add(rects[0].w, 0);

    for(int i = 0; i < n; i++)
    {
        res = query(rects[i].l);
        cout << res << ' ';
        if(i < n - 1)
            add(rects[i + 1].w, res);
    }
    cout << res;

    return 0;
}