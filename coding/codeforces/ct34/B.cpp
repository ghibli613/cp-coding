#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n, m; cin >> n >> m;
    int ans = 0;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int dm; cin >> dm;
        if(dm < 0) a.push_back(dm);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < m && i < int(a.size()); i++)
        ans += a[i] * -1;

    cout << ans;
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