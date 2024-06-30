#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int ans; cin >> ans;
    for(int i = 0; i < 3; i++)
    {
        int a, b; cin >> a >> b;
        if(a == ans) ans = b;
        else if(b == ans) ans = a;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}