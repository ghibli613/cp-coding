#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    int l, p;
    cin >> l >> p;
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    int ans = 0;
    priority_queue<int> max_oil;
    for (int i = 0; i < n; i++)
    {
        if (p < l - a[i].first)
        {
            while (!max_oil.empty() && p < l - a[i].first)
            {
                ans++;
                p += max_oil.top();
                max_oil.pop();
            }
            if (p < l - a[i].first)
            {
                cout << -1 << '\n';
                return;
            }
        }
        max_oil.push(a[i].second);
    }

    while (!max_oil.empty() && p < l)
    {
        ans++;
        p += max_oil.top();
        max_oil.pop();
    }
    if (p < l)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}