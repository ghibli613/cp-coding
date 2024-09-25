#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n + 1, MOD);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> s;
        for (int j = 0; j < 4 && i + j < n; j++)
        {
            if (j && a[i + j] <= a[i + j - 1])
                break;
            s.push_back(a[i + j]);
            int inner = 0;
            for (int k = 0; k < j; k++)
            {
                int diff = s[k + 1] - s[k];
                inner += max(diff / 10 + (diff % 10 != 0) - 1, 0);
            }
            if (inner + s.size() <= 4)
            {
                dp[i + j + 1] = min(dp[i + j + 1], dp[i] + 4 - (int)s.size());
            }
        }
    }
    cout << dp[n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}