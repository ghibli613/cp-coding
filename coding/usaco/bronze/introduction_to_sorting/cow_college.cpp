#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n; 
    vector<ll> c(n);
    for(ll &i : c) cin >> i;
    sort(c.begin(), c.end(), greater<int>());

    ll charges = c[0], profit = c[0];
    for(int i = 1; i < n; i++)
    {
        ll tmp_charges = c[i];
        ll tmp_profit = tmp_charges * (i + 1);
        if(tmp_profit >= profit) 
        {
            charges = tmp_charges;
            profit = tmp_profit;
        }
    }

    cout << profit << ' ' << charges;
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