#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

vector<ll> ways(2e6 + 2, 0);

void solve()
{
    ll n; cin >> n;
    n = n * 2 + 1;
    
    cout << ways[n] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i <= 2e6 + 1; i++)
    {
        ll N = (i - 1) / 2 + 1;
        ways[i] = (i + 1) * N / 2;
        ways[i] %= MOD;
        if(i > 4) ways[i] += ways[i - 4];
        ways[i] %= MOD;
    }

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}