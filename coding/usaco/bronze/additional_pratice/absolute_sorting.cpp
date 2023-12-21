#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = (int)abs(a[0] - a[1]) / 2;
    if(a[0] > a[1]) ans = a[0] - ans;
    else ans += a[0];
    
    for(int i = 1; i < n - 1; i++)
        if(abs(a[i + 1] - ans) < abs(a[i] - ans))
        {
            cout << -1 << "\n";
            return;
        }

    cout << ans << "\n";
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