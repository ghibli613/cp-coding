#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, b; cin >> n >> b;
    vector<pair<int, int>> a(n);
    set<int> hfence;
    set<int> vfence;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        vfence.insert(a[i].first + 1);
        hfence.insert(a[i].second + 1);
    }
    int ans = 100;
    for(int i : vfence)
        for(int j : hfence)
        {
            int top_left = 0;
            int top_right = 0;
            int bot_right = 0;
            int bot_left = 0;
            for(int c = 0; c < n; c++)
                if(a[c].first < i && a[c].second < j)
                    bot_left++;
                else if(a[c].first < i && a[c].second > j)
                    top_left++;
                else if(a[c].first > i && a[c].second < j)
                    bot_right++;
                else top_right++;

            ans = min(ans, max(bot_left, max(top_left, max(bot_right, top_right))));
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