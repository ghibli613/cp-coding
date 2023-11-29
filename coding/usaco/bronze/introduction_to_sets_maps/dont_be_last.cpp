#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    vector<int> cows(7, 0);
    unordered_map<string, int> m;
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        int milk; cin >> milk;
        if(m.count(s) == 0) m[s] = milk;
        else m[s] += milk;
    }
    if(m.size() == 0) cout << "Tie";
    else if(m.size() < 7)
    {
        int min_milk = INT_MAX;
        for(auto &i : m)
        {
            if(i.second < min_milk)
                min_milk = i.second;
        }
        int cnt = 0;
        string ans;
        for(auto&i : m)
        {
            if(i.second == min_milk)
            {
                cnt++;
                ans = i.first;
            }
        }
        if(cnt > 1) cout << "Tie";
        else cout << ans;
    }
    else
    {
        int min_milk = INT_MAX, second_min = INT_MAX;
        for(auto &i : m)
        {
            if(i.second < min_milk)
                min_milk = i.second;
        }
        for(auto&i : m)
        {
            if(i.second < second_min && i.second != min_milk)
                second_min = i.second;
        }
        if(second_min == INT_MAX) cout << "Tie";
        else
        {
            int cnt = 0;
            string ans;
            for(auto&i : m)
            {
                if(i.second == second_min)
                {
                    cnt++;
                    ans = i.first;
                }
            }
            if(cnt > 1) cout << "Tie";
            else cout << ans;
        }
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