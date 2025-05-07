#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 8e2 + 7;
const int N = 8e3 + 7;

int r[M][N];
ll f[M][N], pref[N];
int n, m;

ll solve()
{
    m = min(m, n);

    for(int i = 2; i <= m; i++)
    {
        f[i][i] = pref[i];
        r[i][n + 1] = n;
        r[i][i] = i;
        for(int j = i + 1; j <= n; j++)
            f[i][j] = LONG_LONG_MAX;
    }

    for(int j = 1; j <= n; j++)
    {
        f[1][j] = pref[j] * j;
        r[1][j] = 1;
    }

    for(int i = 2; i <= m; i++)
    {
        for(int j = n; j >= i + 1; j--)
        {
            for(int k = max(1, r[i - 1][j]); k <= min(j, r[i][j + 1]); k++)
            {
                ll cost = f[i - 1][k - 1] + (pref[j] - pref[k - 1]) * (j - k + 1);
                if(f[i][j] > cost)
                {
                    f[i][j] = cost;
                    r[i][j] = k;
                }
            }
        }
    }
    return f[m][n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    pref[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> pref[i];
        pref[i] += pref[i - 1];
    }

    cout << solve();

    return 0;
}