#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    ll ans = 0, flag;
    cin >> flag;
    for(int i = 1; i < n; i++)
    {
        ll tmp; cin >> tmp;
        if(tmp < flag)
            ans += flag - tmp;
        else if(tmp > flag) 
            flag = tmp;
    }
    cout << ans;
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