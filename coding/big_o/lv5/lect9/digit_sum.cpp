#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

ll f[N][2][105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string k;
    cin >> k;
    int d;
    cin >> d;
    int n = k.size();
    k = "0" + k;
    f[0][1][0] = 1;

    for (int id = 0; id < n; id++)
        for (int tight = 0; tight < 2; tight++)
            for (int remain = 0; remain < d; remain++)
                if (f[id][tight][remain])
                {
                    int limit = tight ? (k[id + 1] - '0') : 9;
                    for (int j = 0; j <= limit; j++)
                    {
                        f[id + 1][tight && (j >= limit)][(remain + j) % d] += f[id][tight][remain];
                        f[id + 1][tight && (j >= limit)][(remain + j) % d] %= MOD;
                    }
                }

    ll ans = 0;
    ans = (f[n][0][0] + f[n][1][0]) % MOD;
    ans -= 1;
    if (ans < 0)
        ans += MOD;
    cout << ans;

    return 0;
}