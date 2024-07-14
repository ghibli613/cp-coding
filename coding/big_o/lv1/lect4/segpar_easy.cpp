#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool ok(ll capacity, vector<int> &a, int k)
{
    long long container = 0;
    int numberOfContainer = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (a[i] > capacity) return false;
        if (container + a[i] > capacity)
            container = 0;
        if (container == 0) numberOfContainer++;
        if (numberOfContainer > k) return false;

        container += a[i];
    }
    return true;
}

void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    ll total = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }
    ll ans = 0;
    ll l = 0, r = total;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(ok(mid, a, k))
        {
            ans = mid; 
            r = mid - 1;
        }
        else
            l = mid + 1;
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