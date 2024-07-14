#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; ll l, r; cin >> n >> l >> r;
    vector<ll> coordinate;
    coordinate.push_back(l);
    coordinate.push_back(r);
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        coordinate.push_back(a[i].first);
        coordinate.push_back(a[i].second);
    }
    sort(coordinate.begin(), coordinate.end());
    vector<ll>::iterator it = unique(coordinate.begin(), coordinate.end());
    coordinate.resize(it - coordinate.begin());

    l = lower_bound(coordinate.begin(), coordinate.end(), l) - coordinate.begin();
    r = lower_bound(coordinate.begin(), coordinate.end(), r) - coordinate.begin();

    vector<int> numCover((int)coordinate.size() + 1);

    for(ll i = 0; i < n; i++)
    {
        a[i].first = lower_bound(coordinate.begin(), coordinate.end(), a[i].first) - coordinate.begin();
        a[i].second = lower_bound(coordinate.begin(), coordinate.end(), a[i].second) - coordinate.begin();
        numCover[a[i].first]++;
        numCover[a[i].second + 1]--;
    }

    vector<ll> specialPoint;
    for (int i = 1; i < (ll)numCover.size(); i++)
    {
        numCover[i] += numCover[i - 1];
    }
    for (int i = 0; i < (ll)numCover.size(); i++)
    {
        if (l <= i && i <= r && numCover[i] <= 1)
        {
            specialPoint.push_back(i);
        }
    }
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        ll lIndex = lower_bound(specialPoint.begin(), specialPoint.end(), a[i].first) - specialPoint.begin();
        ll rIndex = upper_bound(specialPoint.begin(), specialPoint.end(), a[i].second) - specialPoint.begin();
        if (lIndex == (ll)specialPoint.size() || rIndex == 0 || lIndex == rIndex)
        {
            res = max(res, coordinate[a[i].second] - coordinate[a[i].first]);
        }
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