#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n), cnt_left(n), cnt_right(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for(int j = 0; j < n - 2; j++)
    {
        fill(cnt_right.begin(), cnt_right.end(), 0);
        for(int k = n - 1; k >= j + 1; k--)
        {
            ans += cnt_left[a[k] - 1] * cnt_right[a[j] - 1];
            cnt_right[a[k] - 1]++;
        }
        cnt_left[a[j] - 1]++;
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}