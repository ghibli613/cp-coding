#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, a, b, c; cin >> n >> a >> b >> c;
    int ans = 0;
    for(int i = 0; i <= b; i++)
    {
        for(int j = 0; j <= c; j++)
        {
            int z = (n - i - 2 * j);
            if(z >= 0 && z * 2 <= a) ans++;
        }
    }
    cout << ans;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    for(int tc = 0; tc < t; tc++)
        solve();

    return 0;
}