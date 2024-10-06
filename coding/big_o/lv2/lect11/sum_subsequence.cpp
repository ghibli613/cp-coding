#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> ans;
    priority_queue<pair<ll, ll>> pq;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            sum += a[i];
        }
        a[i] = abs(a[i]);
    }
    sort(a.begin(), a.end());
    pq.push({sum - a[0], 0});
    ans.push_back(sum);
    while ((int)ans.size() < k)
    {
        auto [val, index] = pq.top();
        pq.pop();
        ans.push_back(val);
        if (index + 1 < n)
        {
            pq.push({val + a[index] - a[index + 1], index + 1});
            pq.push({val - a[index + 1], index + 1});
        }
    }
    cout <<  ans[k - 1] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}