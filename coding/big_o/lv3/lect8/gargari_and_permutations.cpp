#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int NMAX = 1005;
const int KMAX = 10;
int a[KMAX][NMAX], pos[KMAX][NMAX], dp[NMAX];

int main()
{
    int n, k, sol = 0;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            pos[i][a[i][j]] = j;
        }

    for (int i = 1; i <= n; ++i)
    {
        int maxx = 0;
        for (int j = 1; j < i; ++j)
        {
            int ik;
            for (ik = 2; ik <= k && pos[ik][a[1][j]] < pos[ik][a[1][i]]; ++ik)
                ;
            if (ik == k + 1 && dp[j] > maxx)
                maxx = dp[j];
        }
        dp[i] = maxx + 1;
        sol = max(sol, dp[i]);
    }
    cout << sol << "\n";
    return 0;
}