#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
const int N = 1e5 + 10;

int p[N][LOG + 1];
int a[N];

void run_case()
{
    int s, n, k;
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1, j = 1, sum = 0; i <= n; i++)
    {
        while (j <= n && sum + a[j] <= s)
            sum += a[j++];
        p[i][0] = j;
        sum -= a[i];
    }

    for (int i = 0; i <= LOG; i++)
        p[n + 1][i] = n + 1;

    for (int j = 1; j <= LOG; j++)
        for (int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int pos = i;
        for (int j = 0; j <= LOG; j++)
            if (k >> j & 1)
                pos = p[pos][j];

        res = max(res, pos - i);
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        run_case();

    return 0;
}