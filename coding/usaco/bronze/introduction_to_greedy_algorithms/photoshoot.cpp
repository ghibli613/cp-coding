#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    int ans = 0, p = -1;
    for(int i = 0; i < n / 2; i++)
    {
        char x, y;
        cin >> x >> y;
        if(x == y) continue;
        if(x == 'G')
        {
            if(p != -1 && p != 1)
                ans++;
            p = 1;
        }
        else
        {
            if(p != -1 && p != 0)
                ans++;
            p = 0;
        }
    }
    if(p == 1) ans++;
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