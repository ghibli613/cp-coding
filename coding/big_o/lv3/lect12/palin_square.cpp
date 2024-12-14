#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 205;

int n;
bool isl[N][N][N], isc[N][N][N];
char c[N][N];

bool judge(int k, int x, int y, int f)
{
    if (x >= y)
        return true;
    if (f == 0)
    {
        if (c[k][x] != c[k][y])
            return false;
        return judge(k, x + 1, y - 1, f);
    }
    else
    {
        if (c[x][k] != c[y][k])
            return false;
        return judge(k, x + 1, y - 1, f);
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                if (judge(k, i, j, 0))
                    isl[k][i][j] = true;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                if (judge(k, i, j, 1))
                    isc[k][i][j] = true;

    int ans = -1;
    for (int k = n; k > 0; k--)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int ok = 1;
                for (int m = 1; m <= k; m++)
                {
                    if (!isc[j + m - 1][i][i + k - 1] || !isl[i + m - 1][j][j + k - 1])
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                {
                    ans = k;
                    break;
                }
                // cout << "k: " << k << " ans: " << ans << endl;
            }
            if (ans != -1)
                break;
        }
        if (ans != -1)
            break;
    }
    
    cout << (ans == -1 ? 1 : ans) << endl;

    return 0;
}