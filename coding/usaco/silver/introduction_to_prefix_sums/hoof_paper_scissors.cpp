#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<vector<int>> gesture(n + 1, vector<int>(3, 0));
    for(int i = 0; i < n; i++)
    {
        char ch; cin >> ch;
        gesture[i + 1] = gesture[i];
        if(ch == 'H') gesture[i + 1][0]++;
        else if(ch == 'P') gesture[i + 1][1]++;
        else gesture[i + 1][2]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int tmp = max({gesture[i][0], gesture[i][1], gesture[i][2]}) + max({gesture[n][0] - gesture[i][0], gesture[n][1] - gesture[i][1], gesture[n][2] - gesture[i][2]});
        ans = max(ans, tmp);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("hps.in", "r", stdin);
    // freopen("hps.out", "w", stdout);
    
    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}

