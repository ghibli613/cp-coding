#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, l; cin >> n >> l;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    double d = 0;
    for(int i = 1; i < n; i++)
    {
        if(d < a[i] - a[i - 1]) d = a[i] - a[i - 1];
    }
    if(a[0] != 0 && d < (a[0] - 0) * 2)
    {
        d = (a[0] - 0) * 2;
    }
    if(a[n - 1] != l && d < (l - a[n - 1]) * 2)
    {
        d = (l - a[n - 1]) * 2;
    }

    printf("%.2f", d / 2);
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