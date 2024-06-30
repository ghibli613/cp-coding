#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> p(n + 1);
    vector<ll> s(n + 1);
    for(int i = 0; i < n; i++)
    {
        p[i + 1] = gcd(p[i], a[i]);
    }
    for(int i = n; i > 0; i--)
    {
        s[i - 1] = gcd(s[i], a[i - 1]);
    }
    vector<ll> b(n);
    for(int i = 0; i < n; i++)
    {
        b[i] = gcd(p[i], s[i + 1]);
    }
    ll ans = -10e9;
    for(int i = 0; i < n; i++)
    {
        if(b[i] > ans) ans = b[i];
    }
    cout << ans << '\n';
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
