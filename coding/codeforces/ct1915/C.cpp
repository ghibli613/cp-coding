#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n; cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        ll tmp; cin >> tmp;
        sum += tmp;
    }
    ll a = sqrt(sum);
    if(a * a == sum) cout << "YES\n";
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