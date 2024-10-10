#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int n;
vector<vector<ll>> dp;
vector<ll> t, c;

ll backtracking(int i, int sumTime)
{
    if(sumTime >= n) return 0;

    if(i >= n) return 1e18;

    if(dp[i][sumTime] != -1)
        return dp[i][sumTime];

    dp[i][sumTime] = min(backtracking(i + 1, sumTime), c[i] + backtracking(i + 1, sumTime + t[i] + 1));
    return dp[i][sumTime];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    dp.assign(n, vector<ll>(n, -1));
    c.assign(n, 0);
    t.assign(n, 0);

    for(int i = 0; i < n; i++)
        cin >> t[i] >> c[i];
    
    cout << backtracking(0, 0);

    return 0;
}