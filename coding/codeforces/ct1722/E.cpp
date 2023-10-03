#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const double PI = 3.14159265358979323846;

void solve()
{
    int n, q; cin >> n >> q;
    ll a[1001][1001]{0};
    for(int i = 0; i < n; i++)
    {
        int h, w; cin >> h >> w;
        a[h][w] += h * w;
    }

    for(int i = 1; i < 1001; i++)
        for(int j = 1; j < 1001; j++)
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];

    for(int i = 0; i < q; i++)
    {
        int hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb;
        ll ans = 0;
        ans = a[hb-1][wb-1] - a[hs][wb-1] - a[hb-1][ws] + a[hs][ws];
            

        cout << ans << "\n";
    }
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