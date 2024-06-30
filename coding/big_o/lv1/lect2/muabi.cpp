#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(m);
    for(int i = 0; i < m; i++) cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        if(a[i].second <= n)
        {
            ans += a[i].first * a[i].second;
            n -= a[i].second;
            // cout << a[i].second << ' ';
        }
        else
        {
            ans += a[i].first * n;
            n = 0;
            break;
        }
    }
    cout << ans;
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