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
    int x1_bl, y1_bl, x1_tr, y1_tr;
    cin >> x1_bl >> y1_bl >> x1_tr >> y1_tr;
    int x2_bl, y2_bl, x2_tr, y2_tr;
    cin >> x2_bl >> y2_bl >> x2_tr >> y2_tr;

    if(x1_bl >= x2_bl && x1_tr <= x2_tr && y1_bl >= y2_bl && y1_tr <= y2_tr)
        cout << 0;
    else if(x1_bl >= x2_bl && x1_tr <= x2_tr && y1_bl >= y2_bl && y1_bl < y2_tr)
        cout << (x1_tr - x1_bl) * (y1_tr - y2_tr);
    else if(x1_bl >= x2_bl && x1_tr <= x2_tr && y1_tr <= y2_tr && y1_tr > y2_bl)
        cout << (x1_tr - x1_bl) * (y2_bl - y1_bl);
    else if(y1_bl >= y2_bl && y1_tr <= y2_tr && x1_bl >= x2_bl && x1_bl < x2_tr)
        cout << (y1_tr - y1_bl) * (x1_tr - x2_tr);
    else if(y1_bl >= y2_bl && y1_tr <= y2_tr && x1_tr <= x2_tr && x1_tr > x2_bl)
        cout << (y1_tr - y1_bl) * (x2_tr - x1_bl);
    else cout << (x1_tr - x1_bl) * (y1_tr - y1_bl);
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