#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int m; cin >> m; 
    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    int i_a = 0, i_b = 0;
    int sum_a = 0, sum_b = 0;
    int ans = 0;
    while(i_a < n)
    {
        sum_a += a[i_a];
        while(i_b < m && sum_b < sum_a)
        {
            sum_b += b[i_b];
            i_b++;
        }
        if(sum_b == sum_a)
        {
            ans++;
            sum_a = sum_b = 0;
        }
        i_a++;
    }
    if(ans == 0) cout << -1;
    else cout << ans;
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