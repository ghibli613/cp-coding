#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n; cin >> n;
    int x = 0, y = 0, z = 0;
    while(n--)
    {
        int tmp; cin >> tmp;
        x += tmp;
        cin >> tmp; y += tmp;
        cin >> tmp; z += tmp;
    }
    if(x == 0 && y == 0 && z == 0) cout << "YES";
    else cout << "NO";
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