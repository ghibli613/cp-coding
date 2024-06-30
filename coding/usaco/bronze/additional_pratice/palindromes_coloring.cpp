#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, k;
    string s; cin >> n >> k >> s;
    vector<int> a(26, 0);
    for(char i : s)
        a[i - 'a']++;

    int cnt_pair = 0, cnt_odd = 0;
    for(int i : a)
    {
        cnt_pair += i / 2;
        cnt_odd += i % 2;
    }

    int ans = 0;
    ans += 2 * (cnt_pair / k);

    if((cnt_pair % k) * 2 + cnt_odd >= k)
        ans += 1;

    cout << ans << "\n";
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