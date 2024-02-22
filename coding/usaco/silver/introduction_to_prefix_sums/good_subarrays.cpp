#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    vector<int> p(n + 1);
    map<int, ll> mm;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        char ch; cin >> ch;
        a[i] = int(ch - '0');
        p[i + 1] = p[i] + a[i];
        if(p[i + 1] - i - 1 == 0) ans++;
        ans += mm[p[i + 1] - i - 1];
        mm[p[i + 1] - i - 1]++;
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
