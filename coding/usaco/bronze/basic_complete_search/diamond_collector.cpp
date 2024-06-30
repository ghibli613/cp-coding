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
    int N, K; cin >> N >> K;
    vector<int> d(N);
    for(int i = 0; i < N; i++) cin >> d[i];
    
    int result = 0;
    for(int i = 0; i < N; i++)
    {
        int cnt = 0;
        for(int j = 0; j < N; j++)
            if(d[i] <= d[j] && d[j] <= K + d[i]) cnt++;
        
        result = max(result, cnt);
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