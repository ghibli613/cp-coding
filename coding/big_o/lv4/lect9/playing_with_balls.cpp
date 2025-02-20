#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int w, b; cin >> w >> b;
    cout << ((b & 1) ? "1.000000\n" : "0.000000\n");
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