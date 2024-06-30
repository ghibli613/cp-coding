#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dem(ll s)
{
    return s/3 + s/5 + s/7 - s/(5*3) - s/(3*7) - s/(5*7) + s/(3*5*7);
}

void solve()
{
    int id; cin >> id;
    ll k; cin >> k;
    ll left = 3, right = 1e18;
    ll res = 0;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        if(dem(mid) >= k)
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
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