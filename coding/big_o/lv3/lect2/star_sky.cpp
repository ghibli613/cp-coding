#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, c;
    cin >> n >> q >> c;
    vector<vector<vector<int>>> cnt(11, vector<vector<int>>(101, vector<int>(101)));
    for (int i = 0; i < n; i++)
    {
        int x, y, s;
        cin >> x >> y >> s;
        cnt[s][x][y]++;
    }

    for (int p = 0; p <= 10; p++)
    {
        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 100; j++)
            {
                cnt[p][i][j] += cnt[p][i - 1][j] + cnt[p][i][j - 1] - cnt[p][i - 1][j - 1];
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        int ans = 0;
        for (int p = 0; p <= c; p++)
        {
            int brightness = (p + t) % (c + 1);
            int amount = cnt[p][x2][y2] - cnt[p][x1 - 1][y2] - cnt[p][x2][y1 - 1] + cnt[p][x1 - 1][y1 - 1];
            ans += brightness * amount;
        }
        cout << ans << '\n';
    }

    return 0;
}