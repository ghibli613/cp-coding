#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> idx;
    for(int i = 0; i < n; i++) 
        if(s[i] == 'a' || s[i] == 'e') idx.push_back(i);
    
    vector<string> ans;
    for(int i = 0; i < (int)idx.size() - 1; i++)
    {
        string tmp = "";
        tmp.push_back(s[idx[i] - 1]);
        tmp.push_back(s[idx[i]]);
        if(idx[i] + 2 != idx[i + 1])
            tmp.push_back(s[idx[i] + 1]);
        ans.push_back(tmp);
    }
    string tmp;
    tmp.push_back(s[idx[(int)idx.size() - 1] - 1]);
    tmp.push_back(s[idx[(int)idx.size() - 1]]);
    if(idx[(int)idx.size() - 1] != n - 1) tmp.push_back(s[n - 1]);

    for(int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << '.';
    cout << tmp << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}