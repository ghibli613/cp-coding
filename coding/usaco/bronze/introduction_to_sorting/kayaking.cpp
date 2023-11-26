#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> w(2 * n);
    for(int i = 0; i < 2*n; i++) cin >> w[i];
    sort(w.begin(), w.end());
    
    vector<int> gap1(n), gap2(n - 1);
    int ans = 0, max_gap = 0;
    for(int i = 0; i < 2 * n; i += 2)
    {
        gap1[i / 2] = w[i + 1] - w[i];
        ans += gap1[i / 2];
        max_gap = max(max_gap, gap1[i / 2]);
    }
    for(int i = 1; i < 2 * n - 1; i += 2)
        gap2[(i - 1) / 2]  = w[i + 1] - w[i];

    ans -= max_gap;
    int tmp = ans + max_gap;

    for(int i = 0; i < n - 1; i++)
    {
        int sum_gap = tmp;
        sum_gap -= gap1[i];
        for(int j = i; j < n - 1; j++)
        {
            sum_gap += gap2[j] - gap1[j + 1];
            ans = min(sum_gap, ans);        }
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