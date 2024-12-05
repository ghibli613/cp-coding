#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, x; cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    vector<bool> is_used(n, 0);
    int ans = 0;
    for(int i = n - 1, j = 0; i >= 0 && !is_used[i]; i--)
    {
        int tmp = p[i];
        is_used[i] = 1;
        // cout << p[i] << ' ';
        if(!is_used[j] && tmp + p[j] <= x)
        {
            tmp += p[j];
            is_used[j] = 1;
            j++;
        }
        ans++;
        // cout << '\n';
    }
    cout << ans;
    // for(int i = 0; i < n; i++) cout << p[i] << ' ';
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