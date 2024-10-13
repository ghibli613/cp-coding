#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

void solve()
{
    ll g, l; cin >> g >> l;
    ll ab = g * l;
    for(ll i = g; i <= l; i++)
    {
        if(ab % i == 0 && __gcd(i, ab/i) == g)
        {
            cout << i << ' ' << ab/i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}