#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int n_hammters = 0;
    for(int i = 0; i < n; i++) if(s[i] == 'H') n_hammters++;
    for(int i = 0; i < n_hammters - 1; i++) s.push_back(s[i]);
    vector<int> pre_tigers(n + n_hammters);
    for(int i = 0; i < n + n_hammters - 1; i++) 
        if(s[i] == 'T') pre_tigers[i + 1] = pre_tigers[i] + 1;
        else pre_tigers[i + 1] = pre_tigers[i];
    int ans = INT_MAX;
    for(int i = n_hammters; i < n + n_hammters; i++)
    {
        ans = min(ans, pre_tigers[i] - pre_tigers[i - n_hammters]);
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