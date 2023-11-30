#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int k, n; cin >> k >> n;
    vector<ll> a(k, 0), b(n);
    unordered_set<ll> points;

    cin >> a[0];
    for(int i = 1; i < k; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for(int i = 0; i < n; i++)
        cin >> b[i];

    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    for(int i = 0; i < k - n + 1; i++)
        points.insert(b[0] - a[i]);

    int ans = 0;
    for(const ll &i : points)
    {
        unordered_set<ll> marked_points;
        for(int j = 0; j < k; j++)
            marked_points.insert(i + a[j]);

        bool check = true;
        for(int i = 0; i < n; i++)
            if(marked_points.count(b[i]) == 0)
            {
                check = false;
                break;
            }

        if(check) ans++;
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