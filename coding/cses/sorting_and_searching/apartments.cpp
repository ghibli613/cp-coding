#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    multiset<int> b;
    for(int i = 0; i < m; i++)
    {
        int tmp; cin >> tmp;
        b.insert(tmp);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        auto l = b.lower_bound(a[i] - k);
        if(l != b.end() && *l <= a[i] + k)
        {
            ans++;
            b.erase(l);
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

    while(t--)
        solve();

    return 0;
}