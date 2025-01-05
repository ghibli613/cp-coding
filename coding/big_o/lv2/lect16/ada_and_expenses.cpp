#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    ll res = 0, sumBase = 0;
    ll base = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        sumBase = (sumBase + base) % MOD;
        base = (base * 10) % MOD;
        int val = (int)(s[i] - '0');
        res = (res + val * sumBase % MOD * (i + 1) % MOD) % MOD;
    }
    cout << res << '\n';
}