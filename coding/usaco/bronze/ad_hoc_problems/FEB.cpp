#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    if(count(s.begin(), s.end(), 'F') == n) s[0] = 'E';
    vector<int> positions;
    for(int i = 0; i < n; i++)
        if(s[i] != 'F') positions.push_back(i);

    int ones = positions[0] + n - 1 - positions[(int)positions.size() - 1];
    int mn = 0, mx = 0;
    for(int i = 0; i < (int)positions.size() - 1; i++)
    {
        mn += ((positions[i + 1] - positions[i]) & 1) ^ (s[positions[i]] != s[positions[i + 1]]);
        mx += positions[i + 1] - positions[i] - (s[positions[i]] != s[positions[i + 1]]);
    }
    vector<int> ans;
    for(int i = mn; i < ones + mx + 1; i += 1 + (ones == 0))
        ans.push_back(i);
    cout << ans.size() << '\n';
    for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << '\n';
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