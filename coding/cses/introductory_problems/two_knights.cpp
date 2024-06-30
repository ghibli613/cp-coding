#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;

    for(ll i = 0; i < n; i++)
    {
        if(i == 0) cout << 0 << '\n';
        else if(i == 1) cout << 6 << '\n';
        else
        {
            ll k = (i + 1) * (i + 1);
            ll all_possions = k * (k - 1) / 2;
            ll restrict_possions = (i - 1) * i * 4;
            cout << all_possions - restrict_possions << '\n';
        }
    }
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