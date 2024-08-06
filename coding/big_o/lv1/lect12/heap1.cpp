#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> h;
    for(int i = 0; i < n; i++)
    {
        ll tmp; cin >> tmp;
        h.push(tmp);
    }
    
    ll ans = 0;
    while((int)h.size() > 1)
    {
        ll a, b;
        a = h.top(); h.pop();
        b = h.top(); h.pop();
        ans += a + b;
        h.push(a + b);
    }
    cout << ans << '\n';
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