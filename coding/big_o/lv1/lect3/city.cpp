#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int m, n, k; cin >> m >> n >> k;
    vector<vector<int>> a(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<int> c(k);
    for(int i = 0; i < k; i++) cin >> c[i];

    vector<int> sum_a(m * n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            for(int x = -1; x <= 1; x++)
            {
                if(i + x < 0 || i + x >= m) continue;
                for(int y = -1; y <= 1; y++)
                {
                    if(j + y < 0 || j + y >= n || (y == 0 && x == 0)) continue;
                    sum_a[i * n + j] += a[i + x][j + y];
                }
            }
        }

    sort(sum_a.begin(), sum_a.end());

    // for(int i = 0; i < n * m; i++) cout << sum_a[i] << ' ';

    for(int i = 0; i < k; i++)
    {
        vector<int>::iterator it = lower_bound(sum_a.begin(), sum_a.end(), c[i]);
        if(it == sum_a.end())
            cout << "0 ";
        else if(*it == c[i])
            cout << "1 ";
        else cout << "0 ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}