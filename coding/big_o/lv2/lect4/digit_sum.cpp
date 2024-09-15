#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

int digit_sum(ll n) 
{
    int ans = 0;
    while (n) 
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

ll cnt(ll n) 
{
    if (n <= 0) 
        return 0;
    
    if (n % 10 == 9) 
    {
        return 10 * cnt(n/10) + 45*(n/10+1);
    }
    return cnt(n-1) + digit_sum(n);
}

void solve()
{
    ll a, b; cin >> a >> b;
    cout << cnt(b) - cnt(a-1) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 1; tc <= t; tc++)
    {
        // cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}