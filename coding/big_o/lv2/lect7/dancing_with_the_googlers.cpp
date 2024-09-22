#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

void solve()
{
    int n, s, p;
    cin >> n >> s >> p;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        if(p + 2 * max(0, p - 1) <= t)
            ans++;
        else if(s && p + 2 * max(0, p - 2) <= t)
        {
            s--;
            ans++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}