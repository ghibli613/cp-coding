#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(26);
    int ans = 0, sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(cnt[s[i] - 'a'] == 0)
        {
            cnt[s[i] - 'a']++;
            sum++;
        }
        else ans++;
    }
    if(ans + sum > 26) cout << -1;
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