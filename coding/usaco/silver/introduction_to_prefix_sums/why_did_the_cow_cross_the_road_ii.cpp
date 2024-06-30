#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, k, b; cin >> n >> k >> b;
    vector<bool> a(n, true);
    for(int i = 0; i < b; i++)
    {
        int tmp; cin >> tmp;
        a[tmp - 1] = false;
    }
    vector<int> prefix(n + 1, 0);
    for(int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i];
        if(a[i] == false) prefix[i + 1]++;
    }
    int ans = INT_MAX;
    for(int i = k; i <= n; i++)
    {
        ans = min(prefix[i] - prefix[i - k], ans);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("maxcross.in", "r", stdin);
    // freopen("maxcross.out", "w", stdout);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}

