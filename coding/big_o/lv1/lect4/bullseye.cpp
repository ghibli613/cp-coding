#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll find(ll r, ll t)
{
    ll L = 1, R = t;
    while(L <= R)
    {
        ll mid = (L + R) >> 1;
        if((2LL*r + 2LL*mid - 1) <= t/mid) L = mid+1;
        else R = mid-1;
    }
    return L-1;
}

void solve(int tc)
{
    ll r, t; cin >> r >> t;
    cout << "Case #" << tc << ": " << find(r, t) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;

    for(int tc = 0; tc < t; tc++)
        solve(tc + 1);

    return 0;
}