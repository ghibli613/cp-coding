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

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve()
{
    int min_x, max_x, min_y, max_y;
    for(int i = 0; i < 4; i++) cin >> min_x >> min_y >> max_x >> max_y;

    for(int i = 0; i < 4; i++) 
    {
        int x, y;
        cin >> x >> y;
        if(x < min_x) min_x = x;
        if(y < min_y) min_y = y;
        cin >> x >> y;
        if(x > max_x) max_x = x;
        if(y > max_y) max_y = y;
    }

    int side = max(max_x - min_x, max_y - min_y);
    cout << side * side;
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