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

int n;
vector<pair<int, int>> trees;
deque<Line> cht; // convex hull trict

// add line y = ax + b
void add(ll a, ll b)
{
    Line line(a, b);
    while((int)cht.size() >= 2 && cht[(int)cht.size() - 1].intersectX(cht[(int)cht.size() - 2]) >= cht[(int)cht.size() - 1].intersectX(line))
        cht.pop_back();
    cht.push_back(line);
}

ll query(ll x)
{
    while((int)cht.size() > 1 && cht[0].intersectX(cht[1]) <= x)
    {
        cht.pop_front();
    }
    return cht[0].eval(x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    trees.assign(n, {0, 0});

    for(int i = 0; i < n; i++)
        cin >> trees[i].first;
    for(int i = 0; i < n; i++)
        cin >> trees[i].second;

    ll res = 0;
    add(0, 0);

    for(int i = 0; i < n; i++)
    {
        res = query(trees[i].first);
        add(trees[i].second, res);
    }
    cout << res;

    return 0;
}