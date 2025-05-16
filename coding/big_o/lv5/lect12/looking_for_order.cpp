#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 26;

int xN, yN, n;
int x[N], y[N];
int dis[N][N];

int sqr(int x)
{
    return x * x;
}

int distance(int i, int j)
{
    return sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> xN >> yN >> n;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    x[n] = xN; y[n] = yN;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dis[i][j] = distance(i, j);
    
    vector<int> dp(1 << n, MOD), trace(1 << n, -1);
    dp[0] = 0;

    for(int mask = 0; mask < (1 << n); mask++)
    {
        if(dp[mask] == MOD) continue;
        for(int i = 0; i < n; i++)
        {
            if(!(mask >> i & 1))
            {
                int cost = dp[mask] + 2 * dis[i][n];
                if(dp[mask ^ (1 << i)] > cost)
                {
                    dp[mask ^ (1 << i)] = cost;
                    trace[mask ^ (1 << i)] = mask;
                }
                for(int j = i + 1; j < n; j++)
                {
                    if(!(mask >> j & 1))
                    {
                        int nxt = mask ^ (1 << i) ^ (1 << j);
                        int cost = dp[mask] + dis[i][n] + dis[j][n] + dis[i][j];
                        if(dp[nxt] > cost)
                        {
                            dp[nxt] = cost;
                            trace[nxt] = mask;
                        }
                    }
                }
                break;
            }
        }
    }

    cout << dp[(1 << n) - 1] << '\n';
    vector<int> ans;
    for(int mask = (1 << n) - 1; mask != 0; mask = trace[mask])
    {
        int cur = trace[mask] ^ mask;
        ans.push_back(0);
        for(int i = 0; i < n; i++)
            if(cur >> i & 1) ans.push_back(i + 1);
    }
    ans.push_back(0);
    reverse(ans.begin(), ans.end());
    for(int x : ans) cout << x << ' ';

    return 0;
}