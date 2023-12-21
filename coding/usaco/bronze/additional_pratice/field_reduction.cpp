#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<pair<int, int>> cows(n);
    set<pair<int, int>> x_cows, y_cows;
    for(int i = 0; i < n; i++)
    {
        cin >> cows[i].first >> cows[i].second;
        x_cows.insert({cows[i].first, cows[i].second});
        y_cows.insert({cows[i].second, cows[i]. first});
    }

    int ans = INT_MAX;
    for(int i = 0; i <= 3; i++)
        for(int j = 0; j <= 3; j++)
            for(int k = 0; k <= 3; k++)
                for(int l = 0; l <= 3; l++)
                    if(i + j + k + l == 3)
                    {
                        vector<pair<int, int>> tmp;
                        for(int m = 0; m <= i - 1; m++) 
                        {
                            pair<int, int> now = *x_cows.begin();
                            tmp.push_back(now);
                            x_cows.erase(x_cows.find(now));
                            y_cows.erase(y_cows.find({now.second, now.first}));
                        }
                        for(int m = 0; m <= j - 1; m++)
                        {
                            pair<int, int> now = *(--x_cows.end());
                            tmp.push_back(now);
                            x_cows.erase(x_cows.find(now));
                            y_cows.erase(y_cows.find({now.second, now.first}));
                        }
                        for(int m = 0; m <= k - 1; m++)
                        {
                            pair<int, int> now = *y_cows.begin();
                            tmp.push_back({now.second, now.first});
                            x_cows.erase(x_cows.find({now.second, now.first}));
                            y_cows.erase(y_cows.find(now));
                        }
                        for(int m = 0; m <= l - 1; m++)
                        {
                            pair<int, int> now = *(--y_cows.end());
                            tmp.push_back({now.second, now.first});
                            x_cows.erase(x_cows.find({now.second, now.first}));
                            y_cows.erase(y_cows.find(now));
                        }
                        ans = min(ans,((*(--x_cows.end())).first-(*x_cows.begin()).first)*((*(--y_cows.end())).first-(*y_cows.begin()).first));
                        for(pair<int, int> m : tmp)
                        {
                            x_cows.insert(m);
                            y_cows.insert({m.second, m.first});
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