#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    ll LCM = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        LCM = (a[i] * LCM) / __gcd(a[i], LCM);
    }
    ll V = 0;
    for(int i = 0; i < n; i++) V += LCM / a[i];

    ll GCD = __gcd(V, LCM * n);
    cout << LCM * n / GCD << '/' << V / GCD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        solve();
        cout << '\n';
    }

    return 0;
}