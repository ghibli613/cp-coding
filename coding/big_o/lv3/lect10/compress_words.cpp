#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const __uint128_t B = 131;

void solve()
{
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    string ans = "";
    for(int i = 0; i < n; i++)
    {
        int index = -1;
        int l = min((int)ans.size(), (int)a[i].size());
        __uint128_t hashS = 0, hashR = 0;
        __uint128_t pow = 1;
        for(int j = 0; j < l; j++)
        {
            hashS = (hashS * B) + a[i][j];
            hashR = (hashR + ans[(int)ans.size() - 1- j] * pow);
            pow *= B;
            if(hashS == hashR) index = j;
        }
        for(int j = index + 1; j < (int)a[i].size(); j++)
            ans += a[i][j];
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