const int MAX = 1e3 + 10;
const int INF = 1e9;

int a[MAX], pref[MAX];
int f[MAX][MAX], opt[MAX][MAX];
int n;

int solve()
{
    for(int i = 1; i <= n; i++)
    {
        f[i][i] = a[i];
        opt[i][i] = i;
        for(int j = i + 1; j <= n; j++)
            f[i][j] = INF;
    }

    for(int i = n - 1; i >= 1; i--)
        for(int j = i + 1; j <= n; j++)
        {
            for(int k = opt[i][j - 1]; k <= opt[i + 1][j]; k++)
                if(f[i][j] > f[i][k - 1] + f[k + 1][j])
                {
                    f[i][j] = f[i][k - 1] + f[k + 1][j];
                    opt[i][j] = k;
                }
            f[i][j] += pref[j] - pref[i - 1];
        }
    return f[1][n];
}

void test()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    cout << solve();
}