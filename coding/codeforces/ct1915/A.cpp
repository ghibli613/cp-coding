#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int a, b, c; cin >> a >> b >> c;
    if(a == b) cout << c << '\n';
    else if( a == c) cout << b << '\n';
    else cout << a << '\n';
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