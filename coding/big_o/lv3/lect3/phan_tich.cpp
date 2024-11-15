#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    vector<int> changeTypes;
    int n, k; cin >> n >> k;
    for(int i = 2; i <= sqrt(k); i++)
    {
        if(k % i == 0)
        {
            changeTypes.push_back(i);
            if(i != k / i)
                changeTypes.push_back(k / i);
        }
    }
    changeTypes.push_back(k);
    sort(changeTypes.begin(), changeTypes.end());
    vector<vector<int>> ways(n + 1);
    ways[0].push_back(0);

    for (int c = 0; c < (int)changeTypes.size(); ++c)
    {
        for (int i = changeTypes[c]; i < n + 1; ++i)
        {
            if(!ways[i - changeTypes[c]].empty())
            {
                ways[i] = ways[i - changeTypes[c]];
                ways[i].push_back(changeTypes[c]);
            }
        }
        if(!ways[n].empty()) break;
    }
    
    if(ways[n].empty()) 
    {
        cout << 0;
    }
    else
    {
        vector<int> ans;
        map<int, int> cnt;
        for(int i = 0; i < (int)ways[n].size(); i++)
        {
            if(ways[n][i] != 0)
            {
                if(cnt[ways[n][i]] == 0) ans.push_back(ways[n][i]);
                cnt[ways[n][i]]++;
            }
        }
        for(int i = 0; i < (int)ans.size(); i++)
        {
            cout << ans[i] << ' ' << cnt[ans[i]] << '\n';
        }
    }
    // cout << changeTypes.size();
}