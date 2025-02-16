#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans;
    cin >> n;
    ans = n;
    vector<int> d(n + 1, 0);

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        ans = (ll) ans * (++d[u]) % mod * (++d[v]) % mod;
    }

    cout << ans;

    return 0;
}