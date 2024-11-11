#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int>> cnt;
vector<pair<int, pii>> broken_pixels;
int n, m, k, q;
vector<vector<int>> a;

bool bi_search(int p)
{
    cnt.assign(n + 1, vector<int>(m + 1, 0));
    a.assign(n + 1, vector<int>(m + 1, 0));

    for(int i = 0; i <= p; i++)
    {
        a[broken_pixels[i].second.first][broken_pixels[i].second.second] = 1;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + a[i][j];
        }
        
    for(int i = k; i <= n; i++)
        for(int j = k; j <= m; j++)
        {
            if(cnt[i][j] - cnt[i - k][j] - cnt[i][j - k] + cnt[i - k][j - k] == k * k) return true;
        }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k >> q;

    broken_pixels = vector<pair<int, pii>>(q);

    for(int i = 0; i < q; i++)
    {
        int x, y, t; cin >> x >> y >> t;
        broken_pixels[i] = {t, {x, y}};
    }

    sort(broken_pixels.begin(), broken_pixels.end());

    int l = 0, r = q - 1, ans = -1;

    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(bi_search(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else 
        {
            l = mid + 1;
        }
    }
    if(ans != -1) cout << broken_pixels[ans].first;
    else cout << -1;
    
    return 0;
}