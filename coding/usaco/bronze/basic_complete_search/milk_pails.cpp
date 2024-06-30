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
    int X, Y, M; cin >> X >> Y >> M;
    int n = M / X, m = M / Y;
    int result = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
        {
            int tmp = (i * X) + (j * Y);
            if(tmp > M) break;
            result = max(result, tmp);
        }
    cout << result;
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