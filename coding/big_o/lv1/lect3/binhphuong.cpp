#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dem(ll s)
{
    ll d = 0;
    for(ll i = 1; i <= int(sqrt(s)); i++)
        d += int(sqrt(s - i * i));
    return d;
}

void solve()
{
    int id; cin >> id;
    ll k; cin >> k;
    ll left = 2, right = 2*10e12;
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