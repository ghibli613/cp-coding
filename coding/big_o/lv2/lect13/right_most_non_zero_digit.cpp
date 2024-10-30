#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        while (a[i] > 0 && a[i] % 5 == 0)
        {
            a[i] /= 5;
            cnt++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        while (cnt > 0 && a[i] > 0 && (a[i] % 2 == 0))
        {
            a[i] /= 2;
            cnt--;
        }
    }

    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = (ans * a[i] % 10) % 10;
    }

    if (cnt > 0)
        ans = (ans * 5) % 10;

    if (ans != 0)
        cout << ans << '\n';
    else cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}