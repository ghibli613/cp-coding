#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

vector<ll> ways(2e6 + 2, 0);

void solve()
{
    ll n; cin >> n;
    n = n * 2 + 1;
    
    cout << ways[n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i <= 2e6 + 1; i++)
    {
        ll N = (i - 1) / 2 + 1;
        ways[i] = (i + 1) * N / 2;
        ways[i] %= MOD;
        if(i > 4) ways[i] += ways[i - 4];
        ways[i] %= MOD;
    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}

// M = 1e9 + 7;
// x = N % M; \\ N is the money
// y = (x * x) % M;
// ans = (((x + 6) *y) % M + (11 * x + 6) % M) % M;
// ans = (ans * 166666668) % M;

// dp[n,k] = number of ways of dividing 2^k*n into coins of types [1,2,4,8,16,...,2^k].
// dp[n,0] = 1
// dp[n,k] = sum from i=0 to n of dp[i*2,k-1] (where this i is n-(number of coins of type 2^k you take))

// dp[n, 1] = n + 1
// 	dp[0, 1] => 0 to [1, 2] is 1
// 	dp[1, 1] => 2 to [1, 2] is 2
// 	dp[2, 1] => 4 to [1, 2] is 3


// dp[n, 2] = sum from i=0 to n of (2i+1) = (2n+2)*(n+1)/2 = (n+1)^2
// 	dp[0, 2] => 0 to [1, 2, 4] is 1
// 	dp[1, 2] => 4 to [1, 2, 4] is 4
// 	dp[2, 2] => 8 to [1, 2, 4] is 9


// dp[n, 3] = sum from i=0 to n of (2i+1)^2 = 4/3*n^3+4*n^2+11/3*n+1