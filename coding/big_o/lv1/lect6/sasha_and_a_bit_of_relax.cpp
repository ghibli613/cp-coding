#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
    vector<ll> prefix_sum(n + 1);
    map<ll, int> mm, mm1;
    mm[0] = 1;
    ll ans = 0;
    for(int i = 1; i <= n; i++) 
    {
        prefix_sum[i] = a[i - 1] ^ prefix_sum[i - 1];
        if(i % 2 == 0)
        {
            ans += mm[prefix_sum[i]];
            mm[prefix_sum[i]]++;
        }
        else
        {
            ans += mm1[prefix_sum[i]];
            mm1[prefix_sum[i]]++;
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