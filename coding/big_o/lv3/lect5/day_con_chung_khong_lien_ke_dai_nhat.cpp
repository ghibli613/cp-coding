#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1005;
int dp[MAX][MAX];

int lcs(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    dp[0][0] = 0;
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0;
        if (a[i - 1] == b[0])
        {
            flag = 1;
        }
        dp[i][1] = flag;
    }
    flag = 0;
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = 0;
        if (a[0] == b[j - 1])
        {
            flag = 1;
        }
        dp[1][j] = flag;
    }

    for (int i = 2; i <= n + 1; i++)
        for (int j = 2; j <= m + 1; j++)
            if (a[i - 2] == b[j - 2])
                dp[i][j] = dp[i - 2][j - 2] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    return dp[n + 1][m + 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<int> a(m), b(n);

    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    cout << lcs(a, b) << '\n';

    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    return 0;
}