#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;
vector<string> s;
int n;

int solve()
{
    string str = s[0];
    for(int i = 1; i < n; i++)
    {
        int len = min(str.size(), s[i].size());
        for(int j = len; j > 0; j--)
        {
            if(str.substr((int)str.size() - j, j) == s[i].substr(0, j))
            {
                str += s[i].substr(j, s[i].size() - j);
                break;
            }
            if(j == 1) str += s[i];
        }
    }
    return (int)str.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        s.assign(n, "");
        for(int i = 0; i < n; i++) cin >> s[i];
        sort(s.begin(), s.end());
        int ans = MOD;
        do
        {
            ans = min(ans, solve());
        } while (next_permutation(s.begin(), s.end()));
        
        cout << "Case " << tc << ": " << ans << '\n';
    }

    return 0;
}