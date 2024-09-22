#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1000000007;

void solve()
{
    int n, m; cin >> n >> m;
    int mul = 1;

    for(int i = n; i < m + n; i++)
    {
        mul = (mul * (i % 9)) % 9;
        if(mul == 0) break;
    }

    if(mul == 0) cout << 9 << '\n';
    else cout << mul << '\n';
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