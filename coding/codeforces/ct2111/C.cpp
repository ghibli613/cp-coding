#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<pair<ll, pair<int, int>>> pos;
    pos.push_back({a[1], {1, 1}});
    for(int i = 2; i <= n; i++)
    {
        if(a[i] == pos.back().first)
        {
            pos.back().second.second = i;
        }
        else
        {
            pos.push_back({a[i], {i, i}});
        }
    }

    ll ans = LLONG_MAX;
    for(int i = 0; i < (int)pos.size(); i++)
    {
        ll tmp = pos[i].first * (pos[i].second.first - 1) + pos[i].first * (n - pos[i].second.second);
        ans = min(ans, tmp);
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