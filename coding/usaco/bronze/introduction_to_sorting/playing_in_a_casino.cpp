#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    
    int n, m; cin >> n >> m;
    vector<vector<ll>> c(m, vector<ll>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> c[j][i];

    ll ans = 0;
    for(int i = 0; i < m; i++)
    {
        sort(c[i].begin(), c[i].end());
        for(int j = 0; j < n; j++)
            ans += (n - 1 - j) * c[i][j] * -1;
        for(int j = 0; j < n; j++)
            ans += j * c[i][j];
    }
    cout << ans << '\n';

}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}