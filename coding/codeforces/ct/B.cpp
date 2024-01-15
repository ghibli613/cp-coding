#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    ll sum = 0, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i]; sum += a[i];
        if(a[i] % 2 == 1) cnt++;
        if(i < 1) cout << sum << ' ';
        else
        {
            if(cnt % 3 == 1) cout << sum - cnt / 3 - 1 << ' ';
            else cout << sum - cnt / 3 << ' ';
        }
    }
    cout << '\n';
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