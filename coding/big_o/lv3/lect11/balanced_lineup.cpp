#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;
const int LOG_MAX = 20;
const int INF = 1e9;

int a[MAX];
int f1[MAX][LOG_MAX], f2[MAX][LOG_MAX];
int log_2[MAX];
int n, q;

void compute_spare_table()
{
    for(int i = 0; i < n; i++)
        f1[i][0] = a[i];
    for(int i = 0; i < n; i++)
        f2[i][0] = a[i];

    for(int j = 1; (1 << j) <= n; j++)
    {
        int step = 1 << (j - 1);
        for(int i = 0; i + 2 * step <= n; i++)
        {
            f1[i][j] = min(f1[i][j - 1], f1[i + step][j - 1]);
            f2[i][j] = max(f2[i][j - 1], f2[i + step][j - 1]);
        }
    }
}

int minQuery(int l, int r)
{
    int k = log_2[r - l + 1];
    return min(f1[l][k], f1[r - (1 << k) + 1][k]);
}

int maxQuery(int l, int r)
{
    int k = log_2[r - l + 1];
    return max(f2[l][k], f2[r - (1 << k) + 1][k]);
}

void compute_log()
{
    log_2[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        log_2[i] = log_2[i / 2] + 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];

    compute_spare_table();
    compute_log();

    for(int i = 0; i < q; i++)
    {
        int a, b; cin >> a >> b;
        cout << maxQuery(a - 1, b - 1) - minQuery(a - 1, b - 1) << '\n';
    }

    return 0;
}