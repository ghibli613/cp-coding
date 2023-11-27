#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());

    int ans = a[0].first + a[0].second;
    for(int i = 1; i < n; i++)
    {
        if(a[i].first < ans) 
            ans += a[i].second;
        else
            ans = a[i].first + a[i].second;
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