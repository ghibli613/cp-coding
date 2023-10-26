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
        hfence.insert(a[i].first + 1);
        vfence.insert(a[i].second + 1);
    }
    for(int i : hfence)
        for(int j : vfence)
        {
            int top_left = 0;
            int top_right = 0;
            int bot_right = 0;
            int bot_left = 0;
            for(int c = 0; c < n; c++)
                if()
        }
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