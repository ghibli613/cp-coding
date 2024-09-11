#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

void solve(int n)
{
    string ans = "????????????????????????????????";

    for(int t = 0; t < n; t++)
    {
        string q; cin >> q;
        int i; cin >> i;
        if(q == "CLEAR")
        {
            ans[i] = '0';
        }
        else if(q == "SET")
        {
            ans[i] = '1';
        }
        else if(q == "OR")
        {
            int j; cin >> j;
            if(ans[i] == '1' || ans[j] == '1')
            {
                ans[i] = '1';
            }
            else if(ans[i] != '0' || ans[j] != '0')
            {
                ans[i] = '?';
            }
        }
        else
        {
            int j; cin >> j;
            if(ans[i] == '0' || ans[j] == '0')
            {
                ans[i] = '0';
            }
            else if(ans[i] != '1' || ans[j] != '1')
            {
                ans[i] = '?';
            }
        }
    }
    for(int i = 31; i > -1; i--)
    {
        cout << ans[i];
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t = 1;
    // cin >> t;

    // for(int tc = 1; tc <= t; tc++)
    while(true)
    {
        int n; cin >> n;
        if(n == 0) break;
        // cout << "Case #" << tc << ": ";
        solve(n);
        cout << '\n';
    }

    return 0;
}