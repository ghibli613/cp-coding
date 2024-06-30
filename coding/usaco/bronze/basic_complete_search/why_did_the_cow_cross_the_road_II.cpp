#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; cin >> s;
    set<char> cows;
    int ans = 0;
    for(int i = 0; i < 51; i++)
    {
        if(cows.find(s[i]) == cows.end())
        {
            set<char> tmp_cow;
            for(int j = i + 1; j < 52; j++)
            {
                if(s[j] == s[i]) break;
                if(cows.find(s[j]) == cows.end()) continue;
                if(tmp_cow.find(s[j]) == tmp_cow.end())
                {
                    ans++;
                    tmp_cow.insert(s[j]);
                }
                else
                {
                    ans--;
                }
            }
        }
        cows.insert(s[i]);
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