#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    int ans = n - 1;
    for(int i = n - 1; i >= 1; i--)
    {
        if(c[i] > c[i - 1]) ans = i - 1;
        else break;
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