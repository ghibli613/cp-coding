#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<pair<ll, int>> events(2 * n);
    for(int i = 0; i < n; i++)
    {
        ll a, b; cin >> a >> b;
        events[i * 2] = {a, 0};
        events[i * 2 + 1] = {b, 1};
    }
    sort(events.begin(), events.end());
    ll cnt = 0, seg = 0;
    for(int i = 0; i < 2 * n; i++)
    {
        if(events[i].second == 0) seg++;
        else
        {
            seg--;
            cnt += seg;
        }
    }
    cout << cnt << '\n';
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