#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n; cin >> n;
    while(n != 1)
    {
        cout << n << ' ';
        if(n % 2 == 0) n /= 2;
        else
        {
            n *= 3;
            n++;
        }
    }
    cout << 1;
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