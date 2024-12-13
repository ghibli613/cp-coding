#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;
const int LOG_MAX = 20;
const int INF = 1e9;

int a[5][MAX];
int f[5][MAX][LOG_MAX];
int log_2[MAX];
int n, m;
ll K;

void compute_spare_table()
{
    for(int t = 0; t < m; t++)
        for(int i = 0; i < n; i++)
            f[t][i][0] = a[t][i];

    for(int t = 0; t < m; t++)
        for(int j = 1; (1 << j) <= n; j++)
        {
            int step = 1 << (j - 1);
            for(int i = 0; i + 2 * step <= n; i++)
                f[t][i][j] = max(f[t][i][j - 1], f[t][i + step][j - 1]);
        }
}

vector<int> maxQuery(int l, int r)
{
    int k = log_2[r - l + 1];
    vector<int> res;
    for(int t = 0; t < m; t++)
        res.push_back(max(f[t][l][k], f[t][r - (1 << k) + 1][k]));
    return res;
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

    cin >> n >> m >> K;

    vector<vector<int>> A(n, vector<int>(m));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> a[j][i];
        }

    compute_spare_table();
    compute_log();

    int d = 0;
    vector<int> ans(m, 0);
    for(int i = 0; i + d < n; i++)
    {
        while(i + d < n)
        {
            vector<int> tmp = maxQuery(i, i + d);
            ll sum = 0;
            for(int t = 0; t < m; t++) sum += tmp[t];
            if(sum > K) break;
            ans = tmp;
            d++;
        }
    }

    for(int t = 0; t < m; t++)
    {
        cout << ans[t] << ' ';
    }

    return 0;
}