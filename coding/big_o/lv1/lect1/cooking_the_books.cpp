#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int tc)
{
    string s; cin >> s;
    string max_s = s, min_s = s;
    sort(min_s.begin(), min_s.end());
    sort(max_s.begin(), max_s.end(), greater<char>());

    if(min_s[0] == '0')
    {
        int index = 0;
        for(int i = 0; i < int(min_s.size()); i++)
        {
            if(min_s[i] != '0') 
            {
                index = i;
                break;
            }
        }
        char tmp = min_s[0];
        min_s[0] = min_s[index];
        min_s[index] = tmp;
    }

    string ans1 = s, ans2 = s;
    int index = 0;
    for(int i = 0; i < int(max_s.size()); i++)
    {
        if(max_s[i] != s[i])
        {
            index = i;
            break;
        }
    }
    for(int i = int(max_s.size()) - 1; i >= 0 ; i--)
    {
        if(s[i] == max_s[index])
        {
            ans2[index] = max_s[index];
            ans2[i] = s[index];
            break;
        }
    }
    for(int i = 0; i < int(max_s.size()); i++)
    {
        if(min_s[i] != s[i])
        {
            index = i;
            break;
        }
    }
    for(int i = int(max_s.size()) - 1; i >= 0 ; i--)
    {
        if(s[i] == min_s[index])
        {
            ans1[index] = min_s[index];
            ans1[i] = s[index];
            break;
        }
    }
    cout << "Case #" << tc + 1 << ": " << ans1 << " " << ans2 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 0; tc < t; tc++)
        solve(tc);

    return 0;
}