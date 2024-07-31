#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n; 
    vector<ll> a(n); 
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans1 = 0, ans2 = 0, ans3 = 0;
    for(int i = 0; i < n - 2; i++)
    {
        int k = i + 1;
        for(int j = i + 1; j < n - 1; j++)
        {
            while(k + 1 < n && a[k + 1] < a[i] + a[j]) k++;
            ans1 += k - j;
        }
    }

    int l = 0, r = 0, k = 0;
    while(l < n)
    {
        while(r + 1 < n && a[r + 1] == a[l]) r++;
        while(k + 1 < n && a[k + 1] < a[l] * 2) k++;
        ans2 += (ll)(k - r + l) *(r - l + 1) * (r - l) / 2;
        l = r = r + 1;
    }

    for(int i = 0; i < n - 2; i++)
    {
        l = i + 2, r = i + 2;
        for(int j = i + 1; j < n; j++)
        {
            ll c = a[i] * a[i] + a[j] * a[j];
            while (l < n && a[l] * a[l] < c) l++;
            while (r < n && a[r] * a[r] <= c) r++;
            r--;
            if (a[r] * a[r] == c) 
            {
                ans3 += (r - l + 1);
            }
        }
    }
    
    cout << ans1 << ' ' << ans2 << ' ' << ans3;
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