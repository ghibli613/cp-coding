#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; ll k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    if(k > 2) cout << 0 << '\n';
    else 
    {
        if(k == 1)
        {
            ll ans = LONG_LONG_MAX;
            sort(a.begin(), a.end());
            for(int i = 0; i < n - 1; i++)
                if(ans > a[i + 1] - a[i])
                    ans = a[i + 1] - a[i];
            for(int i = 0; i < n; i++)
                if(ans > a[i])
                    ans = a[i];
            cout << ans << '\n';
        }
        else
        {
            set<ll> ms; ll ans = LONG_LONG_MAX;
            for(int i = 0; i < n; i++)
                if(ans > a[i])
                    ans = a[i];
            for(int i = 0; i < n - 1; i++)
                for(int j = i + 1; j < n; j++)
                {
                    ll tmp = abs(a[i] - a[j]);
                    if(ans > tmp)
                        ans = tmp;
                    if(tmp == 0)
                    {
                        cout << 0 << '\n';
                        return;
                    }
                    else
                        ms.insert(tmp);
                }
            
            for(ll i = 0; i < n; i++)
            {
                std::set<ll>::iterator itlow = ms.lower_bound(a[i]);
                if(itlow !=  ms.end() && ans > *itlow - a[i])
                    ans = *itlow - a[i];
                
                if(itlow != ms.begin() && ans > a[i] - *(--itlow))
                    ans = a[i] - *itlow;

            }
            cout << ans << '\n';

        }
    }
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