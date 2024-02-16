#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    vector<ll> a(7);
    for(ll &i : a) cin >> i;
    sort(a.begin(), a.end());
    for(int i = 0; i < 2; i++)
        cout << a[i] << ' ';
    if(a[4] - a[2] == a[0]) cout << a[2];
    else cout << a[3];
    cout << '\n';
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

