#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;

struct Rect {
    ll x1, y1, x2, y2;
	ll area() { return (y2 - y1) * (x2 - x1); }
};

vector<ll> FindPoints(Rect p, Rect q)
{
    // gives bottom-left point
    // of intersection rectangle
    int x5 = max(q.x1, p.x1);
    int y5 = max(q.y1, p.y1);
 
    // gives top-right point
    // of intersection rectangle
    int x6 = min(q.x2, p.x2);
    int y6 = min(q.y2, p.y2);
 
    // no intersection
    if (x5 > x6 || y5 > y6) 
        return vector<ll>(0);

    vector<ll> result;
    result.push_back(x5);
    result.push_back(y5);
    result.push_back(x6);
    result.push_back(y6);
    return result;
}

Rect convert(vector<ll> a)
{
    Rect result;
    result.x1 = a[0];
    result.y1 = a[1];
    result.x2 = a[2];
    result.y2 = a[3];
    return result;
}

ll intersect(Rect p, Rect q) {
    ll tmp = 0;
	ll xOverlap = max(tmp, min(p.x2, q.x2) - max(p.x1, q.x1));
	ll yOverlap = max(tmp, min(p.y2, q.y2) - max(p.y1, q.y1));
	return xOverlap * yOverlap;
}

void solve()
{
    Rect a, b, t;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

    vector<ll> s1 = FindPoints(a, b);
    vector<ll> s2 = FindPoints(a, t);

    if(s1.empty() && s2.empty()) cout << "YES";
    else if (s1.empty())
    {
        if(a.area() == (s2[2] - s2[0]) * (s2[3] - s2[1])) cout << "NO";
        else cout << "YES";
    }
    else if(s2.empty())
    {
        if(a.area() == (s1[2] - s1[0]) * (s1[3] - s1[1])) cout << "NO";
        else cout << "YES";
    }
    else
    {
        Rect tmp1 = convert(s1), tmp2 = convert(s2);
        if(tmp1.area() + tmp2.area() - intersect(tmp1, tmp2) == a.area())
            cout << "NO";
        else cout << "YES";
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}