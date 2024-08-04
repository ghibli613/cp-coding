#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; cin >> s;
    ll res = 0;
    int n = (int)s.size();
    for(int l = 0; l < n; l++)
    {
        int r = n;
        for(int x = l; x < min(n, l + 10); x++)
            for(int k = 1; k < min(n - x, 10); k++)
            {
                if(x + 2 * k >= n) break;
                if(s[x] != s[x + k] || s[x] != s[x + 2 * k]) continue;
                r = min(r, x + 2 * k);
            }

        res += n - r;
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