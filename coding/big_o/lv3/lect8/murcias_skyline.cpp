#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll longest_increas(vector<int> &h, vector<int> &w)
{
    int n = h.size();
    vector<ll> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = w[i];
        for (int j = 0; j < i; j++)
            if (h[j] < h[i])
            {
                dp[i] = max(dp[i], dp[j] + w[i]);
            }
    }
    return *max_element(dp.begin(), dp.end());
}

void solve()
{
    int n; cin >> n;
    vector<int> h(n), w(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> w[i];

    ll increase = longest_increas(h, w);
    for (int &x : h) x = -x;
    ll decrease = longest_increas(h, w);
    if (increase >= decrease)
    {
        cout << "Increasing (" << increase << "). Decreasing (" << decrease << ").\n";
    }
    else 
    {
        cout << "Decreasing (" << decrease << "). Increasing (" << increase << ").\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ". ";
        solve();
    }

    return 0;
}