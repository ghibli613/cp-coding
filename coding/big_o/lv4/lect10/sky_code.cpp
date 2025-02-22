#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int cnt[100007];
ll dp[100007];

ll nc4(ll n)
{
    ll ret = n * (n - 1) * (n - 2) * (n - 3);
    ret /= 24;
    return ret;
}

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        maxx = max(maxx, a);
        cnt[a]++;
    }
    for (int i = maxx; i >= 1; i--)
    {
        ll temp1 = 0;
        ll temp2 = 0;
        for (int j = i; j <= maxx; j += i)
        {
            temp1 += cnt[j];
            temp2 += dp[j];
        }
        dp[i] = nc4(temp1) - temp2;
    }
    cout << dp[1] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n)
        solve();

    return 0;
}