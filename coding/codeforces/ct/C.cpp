#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve()
{
    double k, x; cin >> k >> x;
    double a; cin >> a;
    double a_ = (a - x * (k / (k - 1)));
    if(a_ > 0 && k > x) cout << "YES\n";
    else cout << "NO\n";
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

