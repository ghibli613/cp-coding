#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int mod_max = -1;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        if(a[i] % k == 0)
        {
            cout << 0 << '\n';
            return;
        }
        else
        {
            if(a[i] % k > mod_max) mod_max = a[i] % k;
        }
    }
    if(k != 4)
        cout << k - mod_max << '\n';
    else
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(a[i] % 2 == 0) cnt++;
        if(cnt >= 2) cout << 0 << '\n';
        else cout << min(k - mod_max, 2 - cnt) << '\n';
    }
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