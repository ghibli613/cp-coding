#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, a[N], visited[N][N], dp[N][N];

int calc(int l, int r)
{
    if (l > r)
        return 0;
    if (visited[l][r])
        return dp[l][r];

    visited[l][r] = true;
    dp[l][r] = INT_MIN;
    for (int k = l, sum = 0; k <= r; k++)
    {
        sum += a[k];
        dp[l][r] = max(dp[l][r], sum - calc(k + 1, r));
    }

    for (int k = r, sum = 0; k >= l; k--)
    {
        sum += a[k];
        dp[l][r] = max(dp[l][r], sum - calc(l, k - 1));
    }
    return dp[l][r];
}

int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n && n)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(visited, 0, sizeof(visited));
        cout << calc(1, n) << '\n';
    }
    return 0;
}