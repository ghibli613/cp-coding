#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 410;
const int UP = 200;
int a[N], b[N], dp[N][N];
int x, y, n, d;

int dist(int x, int y)
{
    return x * x + y * y;
}

int solve(int x, int y)
{
    if (dp[x + UP][y + UP] != -1)
        return dp[x + UP][y + UP];

    for (int i = 1; i <= n; i++)
        if (dist(x + a[i], y + b[i]) <= d * d && solve(x + a[i], y + b[i]) == 0)
            return dp[x + UP][y + UP] = 1;

    return dp[x + UP][y + UP] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    
    memset(dp, -1, sizeof(dp));
    if (solve(x, y) == 1)
        cout << "Anton" << "\n";
    else
        cout << "Dasha" << "\n";

    return 0;
}