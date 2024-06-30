#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s; cin >> s;
    int n = (int)s.size();
    int cnt = 1, ans = 1;
    char charac = s[0];
    for(int i = 1; i < n; i++)
    {
        if(s[i] != charac)
        {
            charac = s[i];
            ans = max(ans, cnt);
            cnt = 1;
        }
        else 
        {
            cnt++;
        }
    }
    ans = max(ans, cnt);
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