#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;
const int LOG_MAX = 20;
const int INF = 1e9;

int a[MAX];
int f1[MAX][LOG_MAX], f2[MAX][LOG_MAX];
int log_2[MAX];
int n, k;

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

    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> a[i];

    compute_spare_table();
    compute_log();

    int a_ans = 0;
    for(int i = 0; i + a_ans < n; i++)
    {
        while(i + a_ans < n)
        {
            if(maxQuery(i, i + a_ans) - minQuery(i, i + a_ans) > k) break;
            a_ans++;
        }
    }
    cout << a_ans << ' ';
    vector<pair<int, int>> b;
    for(int i = 0; i + a_ans <= n; i++)
    {
        if(maxQuery(i, i + a_ans - 1) - minQuery(i, i + a_ans - 1) <= k) 
            b.push_back({i + 1, i + a_ans});
    }

    cout << (int)b.size() << '\n';
    for(int i = 0; i < (int)b.size(); i++)
        cout << b[i].first << ' ' << b[i].second << '\n';

    return 0;
}