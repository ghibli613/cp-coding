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

void solve()
{
    ll W, H; cin >> W >> H;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll w, h; cin >> w >> h;

    ll w1 = x1, w2 = W - x2, h1 = y1, h2 = H - y2;

    ll result = 100000001;
    if(H >= h && w2 >= w - w1)
    {
        if(w - w1 < 0) result = 0;
        else result = min(result, w - w1);
    }
    if(H >= h && w1 >= w - w2)
    {
        if(w - w2 < 0) result = 0;
        else result = min(result, w - w2);
    }
    if(W >= w && h2 >= h - h1)
    {
        if(h - h1 < 0) result = 0;
        else result = min(result, h - h1);
    }
    if(W >= w && h1 >= h - h2)
    {
        if(h - h2 < 0) result = 0;
        else result = min(result, h - h2);
    }
    if(result == 100000001) result = -1;
    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}