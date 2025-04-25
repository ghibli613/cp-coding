#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

ll f[20][2][90][90];
int k;

void toList(ll n, vector<int> &digits)
{
    digits.clear();
    while(n)
    {
        digits.push_back(n % 10);
        n /= 10;
    }
    digits.push_back(0);
}

ll dp(vector<int> s)
{
    int n = s.size() - 1;
    f[0][1][0][0] = 1;

    for (int id = 0; id < n; id++)
        for (int tight = 0; tight < 2; tight++)
            for (int remain = 0; remain < k; remain++)
                for (int remain1 = 0; remain1 < k; remain1++)
                    if (f[id][tight][remain][remain1])
                    {
                        int limit = tight ? s[id + 1] : 9;
                        for (int j = 0; j <= limit; j++)
                        {
                            f[id + 1][tight && (j >= limit)][(remain + j) % k][(remain1 * 10 + j) % k] += f[id][tight][remain][remain1];
                        }
                    }
    return f[n][0][0][0] + f[n][1][0][0];
}

ll sumRange(ll a, ll b)
{
    vector<int> digits;
    toList(b, digits);
    reverse(digits.begin(), digits.end());
    memset(f, 0, sizeof(f));
    ll res = dp(digits);
    
    if(a > 0)
    {
        toList(a - 1, digits);
        reverse(digits.begin(), digits.end());
        memset(f, 0, sizeof(f));
        res -= dp(digits);
    }

    return res;
}

void solve()
{
    ll a, b; cin >> a >> b;
    cin >> k;
    if(k > 90) cout << 0 << '\n';
    else
        cout << sumRange(a, b) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 1; tc <= t; tc++)
    {
        cout << "Case " << tc << ": ";
        solve();
    }

    return 0;
}