#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int find_max_index(vector<int> road)
{
    int maxS = 0;
    int ans = 0;
    for(int i = 0; i < (int)road.size(); i++)
        if(road[i] > maxS) maxS = road[i];
    
    for(int i = 0; i < (int)road.size(); i++)
        if(road[i] == maxS) ans++;
    
    return ans;
}

void solve()
{
    int n; cin >> n;
    vector<pair<int, int>> seg(n);
    int minS = 1000, maxS = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> seg[i].first >> seg[i].second;
        minS = min({seg[i].first, seg[i].second, minS});
        maxS = max({seg[i].first, seg[i].second, maxS});
    }

    vector<int> road(maxS - minS);
    for(int i = 0; i < maxS - minS + 1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((i + minS >= seg[j].first && i + minS < seg[j].second) || (i + minS < seg[j].first && i + minS >= seg[j].second)) road[i]++;
        }
    }

    cout << find_max_index(road);
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