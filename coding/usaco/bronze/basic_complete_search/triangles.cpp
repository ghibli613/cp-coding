#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i].first >> a[i].second;

    ll result = 0;
    for(int i = 0; i < n; i++)
    {
        int max_y = 0, max_x = 0;
        for(int j = 0; j < n; j++)
        {
            if(a[i].first == a[j].first)
            {
                if(abs(a[i].second - a[j].second) > max_y) max_y = abs(a[i].second - a[j].second);
            }
        }
        for(int j = 0; j < n; j++)
        {
            if(a[i].second == a[j].second)
            {
                if(abs(a[i].first - a[j].first) > max_x) max_x = abs(a[i].first - a[j].first);
            }
        }
        ll tmp = max_x * max_y;
        if(tmp > result) result = tmp;
    }
    cout << result;
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