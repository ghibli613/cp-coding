#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s1, s2; cin >> s1 >> s2;
    vector<int> cnt1(256), cnt2(256);
    for(int i = 0; i < (int)s1.size(); i++) cnt1[s1[i]]++;
    for(int i = 0; i < (int)s2.size(); i++) cnt2[s2[i]]++;

    int ans = 0;
    for(int i = 0; i < 256; i++)
        ans += abs(cnt1[i] - cnt2[i]);
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