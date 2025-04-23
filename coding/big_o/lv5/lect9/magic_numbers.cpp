#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 2e3 + 7;

int m, d;
ll z[N][2][N];

bool good(string s)
{
    int rm = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        int p = int(s[i] - '0');
        if ((i & 1) && p != d)
            return false;
        if (!(i & 1) && p == d)
            return false;
        rm = (rm * 10 + p) % m;
    }
    return !rm;
}

ll dp(string s)
{
    int n = s.size();
    s = "0" + s;
    for (int i = 0; i <= n; i++)
        for (int k = 0; k < 2; k++)
            for (int j = 0; j < m; j++)
                z[i][k][j] = 0;

    z[0][1][0] = 1;
    for (int id = 0; id < n; id++)
        for (int tight = 0; tight < 2; tight++)
            for (int j = 0; j < m; j++)
                if (z[id][tight][j])
                {
                    int limit = tight ? (s[id + 1] - '0') : 9;
                    for (int p = 0; p <= limit; p++)
                    {
                        int next_id = id + 1;
                        if ((next_id & 1) && p == d)
                            continue;
                        if (!(next_id & 1) && p != d)
                            continue;
                        
                        int next_j = (j * 10 + p) % m;
                        int next_tight = tight && (p == limit);
                        z[next_id][next_tight][next_j] += z[id][tight][j];
                        z[next_id][next_tight][next_j] %= MOD;
                    }
                }

    ll ans = 0;
    ans = (z[n][0][0] + z[n][1][0]) % MOD;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> d;
    string a, b;
    cin >> a >> b;

    ll ans = 0;
    ans += dp(b) - dp(a);
    if (ans < 0)
        ans += MOD;
    ans += good(a);
    ans %= MOD;
    cout << ans;

    return 0;
}