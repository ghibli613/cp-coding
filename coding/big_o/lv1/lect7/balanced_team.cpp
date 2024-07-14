#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int j = 0, res = 0;
    for(int i = 0; i < n; i++)
    {
        while(a[i] - a[j] > 5)
            j++;
        res = max(res, i - j + 1);
    }
    cout << res;
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