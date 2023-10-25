#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, m; cin >> n >> m;
    vector<string> spot_cows(n), plain_cows(n);
    for(int i = 0; i < n; i++)
        cin >> spot_cows[i];
    for(int i = 0; i < n; i++)
        cin >> plain_cows[i];

    int ans = 0;
    for(int i = 0; i < m - 2; i++)
        for(int j = i + 1; j < m - 1; j++)
            for(int t = j + 1; t < m; t++)
            {
                set<string> set_spot_cows;
                for(int x = 0; x < n; x++)
                {
                    string s;
                    s.push_back(spot_cows[x][i]);
                    s.push_back(spot_cows[x][j]);
                    s.push_back(spot_cows[x][t]);
                    set_spot_cows.insert(s);
                }
                bool check = false;
                for(int x = 0; x < n; x++)
                {
                    string s;
                    s.push_back(plain_cows[x][i]);
                    s.push_back(plain_cows[x][j]);
                    s.push_back(plain_cows[x][t]);
                    if(set_spot_cows.find(s) != set_spot_cows.end())
                    {
                        check = true;
                        break;
                    }
                }
                if(!check) ans++;
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