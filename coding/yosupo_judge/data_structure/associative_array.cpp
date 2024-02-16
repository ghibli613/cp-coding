#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int q; cin >> q;
    map<ll, ll> mm;
    for(int i = 0; i < q; i++)
    {
        int flag; cin >> flag;
        if(!flag)
        {
            ll k, v; cin >> k >> v;
            mm[k] = v;
        }
        else 
        {
            ll k; cin >> k;
            cout << mm[k] << '\n';
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

