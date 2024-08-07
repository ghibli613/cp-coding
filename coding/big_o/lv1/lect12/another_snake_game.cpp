#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; cin >> s;
    int n = (int)s.size();
    int ans = 0, tmp = 0;
    vector<bool> check(26);
    vector<int> index(26);
    for(int i = 0; i < n; i++)
    {
        if(check[s[i] - 'a'] == false)
        {
            index[s[i] - 'a'] = i;
            check[s[i] - 'a'] = true;
            tmp++;
        }
        else
        {
            i = index[s[i] - 'a'];
            check = vector<bool>(26);
            ans = max(ans, tmp);
            tmp = 0;
        }
    }
    ans = max(ans, tmp);
    cout << ans << '\n';
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