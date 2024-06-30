#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> a(n);
    map<int, int> num, last;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        num[a[i]]++;
        last[a[i]] = i;
    }
    
    // segment
    int l = 0, r = -1, ans = 0, max_num = 0;
    for(int i = 0; i < n; i++)
    {
        r = max(r, last[a[i]]);
        max_num = max(max_num, num[a[i]]);
        if(i == r)
        {
            ans += r - l + 1 - max_num;
            l = r + 1;
            max_num = 0;
            r = 0;
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