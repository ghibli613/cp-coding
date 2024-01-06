#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll a, b; cin >> a >> b;
    if((2*a - b) % 3 != 0)
        cout << "NO\n";
    else if((2*a - b) / 3 < 0)
        cout << "NO\n";
    else if((2*b - a) % 3 != 0)
        cout << "NO\n";
    else if((2*b - a) / 3 < 0)
        cout << "NO\n";
    else 
        cout << "YES\n";
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