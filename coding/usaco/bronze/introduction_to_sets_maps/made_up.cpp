#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n), b(n);
    unordered_map<ll, ll> b_star;
    unordered_map<ll, ll> c;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= 1;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i] -= 1;
    }
    for(int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        c[tmp - 1]++;
    }

    for(int i = 0; i < n; i++)
        b_star[b[i]] += c[i];

    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += b_star[a[i]];
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