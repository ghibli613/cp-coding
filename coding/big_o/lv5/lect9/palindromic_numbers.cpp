#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1001;

ll dp[20][2][20];

ll var;
int digits[20];
int n;

bool check(int index, int len)
{
    ll x = 0;
    for (int i = n - 1; i > index; i--)
        x = 10 * x + digits[i];
    
    for (int i = index + ((len % 2) ? 2 : 1); i < len; i++)
        x = x * 10 + digits[i];
    
    if (x <= var)
        return 1;
    return 0;
}

ll f(int id, bool tight, int len)
{
    if (id == len / 2 - 1)
    {
        if (tight && len)
            return check(id, len);
        return 1;
    }

    if (!tight && dp[id][tight][len] != -1)
        return dp[id][tight][len];

    ll res = 0;
    int limit = tight ? digits[id] : 9;
    for (int j = 0; j <= limit; j++)
    {
        int next_len = len;
        if(j && len == 0) next_len = id + 1;
        res += f(id - 1, tight && (j == limit), next_len);
    }
    
    if (tight)
        return res;
    return dp[id][tight][len] = res;
}

ll solve(ll a)
{
    var = a;
    n = 0;
    while(a)
    {
        digits[n] = a % 10;
        a /= 10;
        n++;
    }
    memset(dp, -1, sizeof(dp));
    return f(n - 1, true, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    int cs = 0;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        cout << "Case " << ++cs << ": " << solve(b) - solve(a - 1) << "\n";
    }
    return 0;
}