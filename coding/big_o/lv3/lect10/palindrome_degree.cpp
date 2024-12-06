#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll B = 131;

void solve()
{
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> degree(n + 1, 0);
    ll pow = 1;
    ll hashS = 0, hashR = 0;
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        hashS = (hashS * B) + s[i - 1];
        hashR = (hashR + s[i - 1] * pow);
        pow = pow * B;
        if(hashS == hashR)
        {
            // cout << i << ' ';
            degree[i] = degree[i / 2] + 1;
            res += degree[i];
        }
    }
    cout << res;
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