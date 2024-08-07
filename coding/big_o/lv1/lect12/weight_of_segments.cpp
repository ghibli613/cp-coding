#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    stack<int> stk;
    vector<int> l(n), r(n, -1);
    for(int i = 0; i < n; i++)
    {
        while (!stk.empty() && a[i] >= a[stk.top()])
        {
            r[stk.top()] = i - 1;
            stk.pop();
        }
        if(stk.empty()) l[i] = 0;
        else l[i] = stk.top() + 1;
        stk.push(i);
    }
    for(int i = 0; i < n; i++) if(r[i] == -1) r[i] = n - 1;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += (ll)(i - l[i] + 1) * (ll)(r[i] - i + 1) * a[i];
        // cout << l[i] << ' ' << r[i] << '\n';
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